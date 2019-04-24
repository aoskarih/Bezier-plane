
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <misc.h>
#include <vector>
#include <string>
#include <mandelbrot.h>

double iter_func(double re, double im, int itr) {
    double tx = 0;
    double ty = 0;
    double p = sqrt((re - 0.25)*(re - 0.25) + im*im);
    if (re <= p - 2*p*p + 0.25 || (re+1)*(re+1) + im*im <= 0.0625) {
        return 0.0;
    }
    for (int i = 0; i < itr; i++) {
        double r2 = tx*tx + ty*ty;
        if (r2 > 4) {
            return 1.0-double(i%100)/100;
        }
        double tmpx = tx*tx - ty*ty + re;
        double tmpy = 2*tx*ty + im;
        if (tx == tmpx && ty == tmpy) {
            return 0.0;
        }
        tx = tmpx;
        ty = tmpy;
    }
    return 0.0;
}

std::vector<unsigned char> calc_pixels(double cx, double cy, double side) {
    double d = side/SCREEN_WIDTH;
    double x_off = side/2;
    double y_off = side*SCREEN_HEIGHT/(2*SCREEN_WIDTH);
    std::vector<unsigned char> pixels( SCREEN_WIDTH * SCREEN_HEIGHT * 4, 0 );

    for (unsigned int x = 0; x < SCREEN_WIDTH; x++) {
        for (unsigned int y = 0; y < SCREEN_HEIGHT; y++) {
            double re = cx + (double(x) + 0.5)*d - x_off;
            double im = cy + (double(y) + 0.5)*d - y_off;

            double value = iter_func(re, im, 1000);

            const unsigned int offset = (SCREEN_WIDTH*4*y) + x*4;
            if (value == 0.0) {
                pixels[offset + 0] = 0;     // b
                pixels[offset + 1] = 0;     // g
                pixels[offset + 2] = 0;     // r
                pixels[offset + 3] = 256;   // a
            } else {
                pixels[offset + 0] = 100;
                pixels[offset + 1] = 100;
                pixels[offset + 2] = 127-127*sin(2*value*3.14159);
                pixels[offset + 3] = 256;
            }
        }
    }
    printf("%.14f\n",side);
    return pixels;
}
