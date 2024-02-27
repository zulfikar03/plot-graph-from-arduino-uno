import serial as sr
import matplotlib.pyplot as plt
import numpy as np
import time
import datetime
import pandas as pd
s = sr.Serial("COM4", 9600)

with plt.ion():
    plt.figure(figsize=(10,5))
    plt.show()

data = np.array([])
max = 400
dt = 0.1
timeArray = np.arange(0,max, dt)
i = 0
while True:
    i += 1
    val = s.readline()
    val = float(val.decode("utf").rstrip("\n"))
    data = np.append(data, val)
    print(f"{timeArray[i]} > {val}")
    plt.cla()
    plt.plot(data)
    plt.pause(0.01)
    if len(data) == max:
        break;
s.close()

df = pd.DataFrame({"Waktu (sekon)" : timeArray[:len(data)],
                   "Tegangan (V)" : data})
df.to_csv("A_0_20s_2.csv")
