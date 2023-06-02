import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline

df = pd.read_csv('data.csv')

x = df['Array Size']
y_serial = df['Serial']
y_pthread = df['pthread']
y_openmp = df['openMP']

num_points = 100
x_smooth = np.linspace(x.min(), x.max(), num_points)

spl_serial = make_interp_spline(x, y_serial)
y_serial_smooth = spl_serial(x_smooth)
spl_pthread = make_interp_spline(x, y_pthread)
y_pthread_smooth = spl_pthread(x_smooth)
spl_openmp = make_interp_spline(x, y_openmp)
y_openmp_smooth = spl_openmp(x_smooth)

plt.plot(x_smooth, y_serial_smooth, label='Serial')
plt.plot(x_smooth, y_pthread_smooth, label='Pthread')
plt.plot(x_smooth, y_openmp_smooth, label='OpenMP')

plt.xlabel('Array Size')
plt.ylabel('Time (seconds)')
plt.title('Performance of an Algorithm')
plt.legend()
plt.show()

