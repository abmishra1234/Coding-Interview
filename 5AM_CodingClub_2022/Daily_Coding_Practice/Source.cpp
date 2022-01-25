#include <iostream>
#include "Planet.h"
using namespace std;
#if 0

int main() {
    Planet earth(6.38e6, 5.98e24);
    double m = earth.getMass();
    cout << "Mass: " << m << endl;
    double gravStrength = earth.calculateGravity();
    cout << "Gravitational strength: " << gravStrength << endl;
}
#endif//0