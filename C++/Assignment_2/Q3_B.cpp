#include <iostream>
using namespace std;

namespace Physics {

    double clamp(double val, double min, double max) {

        if(val < min)
            return min;
        else if(val > max)
            return max;
        else
            return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}

namespace GameMath {

    int clamp(int val, int min, int max) {

        if(val < min)
            return min;
        else if(val > max)
            return max;
        else
            return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}


int main() {
    
    cout << "Physics Clamp: "<< Physics::clamp(150.5, 0.0, 100.0) << endl;

    cout << "Physics Lerp: "<< Physics::lerp(10.0, 20.0, 0.5) << endl;

    cout << "GameMath Clamp: "<< GameMath::clamp(120, 0, 100) << endl;

    cout << "GameMath Lerp: "<< GameMath::lerp(10.0, 20.0, 0.5) << endl;

    {
        using namespace Physics;

        cout << "Block Scope Physics Clamp: "<< clamp(200.0, 0.0, 100.0) << endl;

        cout << "Block Scope Physics Lerp: "<< lerp(0.0, 100.0, 0.25) << endl;
    }

    cout << "GameMath Clamp Again: "<< GameMath::clamp(50, 0, 100) << endl;

    return 0;
}