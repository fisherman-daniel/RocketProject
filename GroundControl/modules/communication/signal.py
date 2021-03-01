from enum import Enum
import json

# notes:
# use ArduinoJson on arduino's end.
# msgpack can be used for tiny binary json messages


class Direction(str, Enum):
    UPLINK = 'uplink',
    DOWNLINK = 'downlink'


class SignalMember:
    def __init__(self, name: str, value, units: str):
        self.name = name
        self.value = value
        self.units = units


class Signal:
    def __init__(self, name: str, direction: Direction, interval: float, members: [SignalMember]):
        self.name = name
        self.direction = direction
        self.interval = interval
        self.members = members

    def to_packet(self) -> str:
        packet = json.dumps({
            'name': self.name,
            'data': {x.name: x.value for x in self.members}
        })
        return packet

    def update_from_packet_data(self, packet: str):
        packet = json.loads(packet)
        if packet['name'] != self.name:
            raise RuntimeError('update with wrong packet name')
        data = packet['data']
        for member in self.members:
            member.value = data[member.name]

    @staticmethod
    def from_json(filename: str) -> []:
        signals_dict = []
        signals_obj = []
        with open(filename, 'r') as infile:
            signals_dict = json.load(infile)['signals']
        for signal_dict in signals_dict:
            signal_obj = Signal(signal_dict['name'], Direction(signal_dict['direction']), signal_dict['interval'], [
                SignalMember(x['name'], x['value'], x['units']) for x in signal_dict['data']])
            signals_obj.append(signal_obj)
        return signals_obj
