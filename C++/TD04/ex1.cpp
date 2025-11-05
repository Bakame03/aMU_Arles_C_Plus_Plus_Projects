#include <iostream>
#include "../utils.hpp"

int main(){
    Point a;
    Point b;
    double distanceEuclidienne;
    getDistanceEuclidienne(a, b, distanceEuclidienne);
    std::cout << "Distance euclidienne entre les points a et b : " << distanceEuclidienne << std::endl;
    return 0;
}
