#include <iostream>
#include <Player.h>

using std::cout;
using std::endl;

Player::Player(double nx,double ny) {
    x = nx;
    y = ny;
}

void Player::print() {
    cout << x << ", " << y << endl;
}
