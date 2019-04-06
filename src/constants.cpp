#include <map>
#include <string>
#include <constants.h>

struct color {
    int r;
    int g;
    int b;
    int a;
};

color c[16];
std::map<std::string, color> col;

c[0].r = 29;    c[0].g = 43;    c[0].b = 83;    c[0].a = 255;
c[1].r = 126;   c[1].g = 37;    c[1].b = 83;    c[1].a = 255;
c[2].r = 0;     c[2].g = 135;   c[2].b = 81;    c[2].a = 255;
c[3].r = 171;   c[3].g = 82;    c[3].b = 54;    c[3].a = 255;
c[4].r = 95;    c[4].g = 87;    c[4].b = 79;    c[4].a = 255;
c[5].r = 194;   c[5].g = 195;   c[5].b = 199;   c[5].a = 255;
c[6].r = 255;   c[6].g = 241;   c[6].b = 232;   c[6].a = 255;
c[7].r = 255;   c[7].g = 0;     c[7].b = 77;    c[7].a = 255;
c[8].r = 255;   c[8].g = 163;   c[8].b = 0;     c[8].a = 255;
c[9].r = 255;   c[9].g = 236;   c[9].b = 39;    c[9].a = 255;
c[0].r = 0;     c[0].g = 228;   c[0].b = 54;    c[0].a = 255;
c[1].r = 41;    c[1].g = 173;   c[1].b = 255;   c[1].a = 255;
c[2].r = 131;   c[2].g = 118;   c[2].b = 156;   c[2].a = 255;
c[3].r = 255;   c[3].g = 119;   c[3].b = 168;   c[3].a = 255;
c[4].r = 255;   c[4].g = 204;   c[4].b = 170;   c[4].a = 255;
c[5].r = 0;     c[5].g = 0;     c[5].b = 0;     c[5].a = 255;

col["dark blue"] = c[0];
col["purple"] = c[1];
col["dark green"] = c[2];
col["brown"] = c[3];
col["dark grey"] = c[4];
col["grey"] = c[5];
col["white"] = c[6];
col["red"] = c[7];
col["orange"] = c[8];
col["yellow"] = c[9];
col["green"] = c[10];
col["blue"] = c[11];
col["spale"] = c[12];
col["pink"] = c[13];
col["peach"] = c[14];
col["black"] = c[15];
