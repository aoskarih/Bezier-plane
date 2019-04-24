import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import matplotlib as mpl

mpl.rcParams['toolbar'] = 'None'

fig = plt.figure(figsize=(10, 10))#, facecolor='black')
plt.subplots_adjust(left=0, bottom=0, right=1, top=1)
ax = plt.subplot(111, frameon=False)


res = 960
itr = 1000
side = 2
x0, y0 = -0.7436, 0.1318 # center
x = 0
y = 0
n = 2
steps = 100
prog = 0

img = ax.imshow(np.ones([res,res]), interpolation="nearest", cmap="viridis", vmin=0, vmax=1)

def mandelbrot(re, im):
    tx = x
    ty = y
    p = np.sqrt((re - 0.25)**2 + im**2)
    if (re <= p - 2*p*p + 0.25) or ((re+1)**2 + im**2 <= 0.0625):
        return 0
    for i in range(itr):
        r2 = tx**2 + ty**2
        if r2 > 4:
            return 1-i/itr
        #rn = r2**(0.5 * n)
        #th = n*np.arctan2(ty, tx)
        #tmpx, tmpy = rn*np.cos(th) + re, rn*np.sin(th) + im
        tmpx, tmpy = tx*tx - ty*ty + re, 2*tx*ty + im
        if tx == tmpx and ty == tmpy:
            return 0
        tx, ty = tmpx, tmpy
    return 0

def loop(num):
    global n
    global side
    global prog
    arr = np.empty([res, res])
    d = side/res
    for i in range(0, res):
        for j in range(0, res):
            re = x0 + (i+0.5)*d - side/2
            im = y0 + (j+0.5)*d - side/2
            arr[j][i] = mandelbrot(re, im)
        #print(str(i+1) + "/" + str(res))
    prog += 1
    print("prog: " +str(prog) + "/" + str(steps))
    img.set_data(arr)
    side *= 0.9

def main():
    #cb = plt.colorbar(img)

    ani = animation.FuncAnimation(fig, loop, frames=np.arange(0, steps), interval=17)
#    plt.show()
    ani.save('brot.mp4', writer="ffmpeg")

if __name__ == "__main__":
    main()
