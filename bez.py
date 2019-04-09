import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import random

fig1 = plt.figure(num=None, figsize=(10, 10), dpi=80, facecolor='w', edgecolor='k')
i = 0

plt.xlim(-1, 1)
plt.ylim(-1, 1)

def bez(t, p):
    x = (1 - t)**3*p[0][0] + 3*(1 - t)**2*t*p[1][0] + 3*(1 - t)*t**2*p[2][0] + t**3*p[3][0]
    y = (1 - t)**3*p[0][1] + 3*(1 - t)**2*t*p[1][1] + 3*(1 - t)*t**2*p[2][1] + t**3*p[3][1]
    l = [x,y]
    return l

def bez_der(t, p):
    x = 3*(1 - t)**2*(p[1][0] - p[0][0]) + 6*(1 - t)*t*(p[2][0] - p[1][0]) + 3*t**2*(p[3][0] - p[2][0])
    y = 3*(1 - t)**2*(p[1][1] - p[0][1]) + 6*(1 - t)*t*(p[2][1] - p[1][1]) + 3*t**2*(p[3][1] - p[2][1])
    l = [x,y]
    return l

def rot(v, t):
    x = np.cos(t)*v[0] - np.sin(t)*v[1]
    y = np.cos(t)*v[1] + np.sin(t)*v[0]
    l = [x,y]
    return l

def unit(v):
    d = np.dot(v,v)
    l = [v[0]/d, v[1]/d]
    return l

def line():
    global i
    p = np.random.rand(4,2)*2-1
    line_x = []
    line_y = []
    ts = np.arange(0,1,0.001)
    for t in ts:
        x,y = bez(t,p)
        line_x.append(x)
        line_y.append(y)
    if i%10 == 0: print(i)
    i += 1
    plt.plot(line_x,line_y)
    line_x = []
    line_y = []
    for t in ts:
        x,y = bez(t,p)
        nx, ny = rot(unit(bez_der(t,p)), np.pi/2)
        x += nx*0.01*np.sin(500*t)
        y += ny*0.01*np.sin(500*t)
        line_x.append(x)
        line_y.append(y)
    plt.plot(line_x,line_y)

def main():
    np.random.seed(42)
    for i in range(1):
        line()
    plt.show()

if __name__ == "__main__":
    main()
