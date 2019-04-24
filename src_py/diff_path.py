import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

mpl.rcParams['toolbar'] = 'None'

fig = plt.figure(figsize=(10, 10))

res = 1000
len = 10
x0, y0 = 1, 1

def dx(r, dt):
    return ()*dt

def dy(r, dt):
    return ()*dt

def main():
    arr_x = np.empty(res)
    arr_y = np.empty(res)
    dt = len/res
    arr_x[0] = x0
    arr_y[0] = y0
    for i in range(1, res):
        arr_x[i] = arr_x[i-1] + dx([arr_x[i-1],arr_y[i-1]], dt)
        arr_y[i] = arr_y[i-1] + dy([arr_x[i-1],arr_y[i-1]], dt)
    print("done")
    plt.plot(arr_x, arr_y)
    plt.show()


if __name__ == "__main__":
    main()
