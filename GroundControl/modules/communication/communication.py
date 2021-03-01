from threading import Thread, Event
from queue import Queue
from serial import Serial
import json


class Communication:
    def __init__(self, config: dict):
        port = Serial(
            port=config['port'], baudrate=config['baud'], timeout=0, write_timeout=0)
        # timeouts set to 0 so that calls are not blocking.
        # need to check whether write_timeout=0 still allows any writing!

        # create two queues for passing packets in and out
        self.downlink_queue = Queue(maxsize=5)
        self.uplink_queue = Queue(maxsize=5)

        # create a flag to stop the queue
        self.halt_flag = Event()

        # create and start a thread to do the serial port I/O
        self.comms_thread = Thread(
            target=self.comms_thread, args=(port,))
        self.comms_thread.start()

    def comms_thread(self, port: Serial):
        port.open()
        local_rx_buffer = ''

        while not self.halt_flag:
            # read all available bytes and append to working string
            # this is not blocking since it just accesses the port's in-buffer
            if port.in_waiting:
                local_rx_buffer += port.read_all()
            # check if we've reached a newline - these come at the end of each packet
            if '\n' in local_rx_buffer:
                # separate the buffer into packets. there's probably just one, but if there
                # was a large chunk just read in there might be more.
                for possible_packet in local_rx_buffer.split('\n'):
                    # some packets will be bad or incomplete.
                    # only add the good ones to the queue
                    try:
                        json.loads(possible_packet)
                    except ValueError:
                        continue
                    else:
                        self.downlink_queue.put(possible_packet)
                # keep the buffer after the last newline - it could be the first part of the next packet
                local_rx_buffer = local_rx_buffer.split('\n', 1)[-1]

            # add all messages in uplink queue to port's out-buffer
            while self.uplink_queue.qsize():
                port.write(self.uplink_queue.get())

        # cleanup before thread exit
        port.close()
