# looptest.py
# test timing of Python loops and how accurate/reliable it would be for the onboard controls

import math
import time
import matplotlib.pyplot as plt
import numpy as np

# just some garbage code payload to run


def think():
    x = 0
    for _ in range(10000):
        x += math.sin(x)


N_TRIALS = 100
LOOP_TIME = 0.01

data = []

print('starting')
for _ in range(N_TRIALS):
    t0 = time.time()
    while((time.time() - t0) < 0.01):
        pass
    t1 = time.time()
    data.append(t1-t0)

print(np.mean(data))

plt.plot(data)
plt.show()
