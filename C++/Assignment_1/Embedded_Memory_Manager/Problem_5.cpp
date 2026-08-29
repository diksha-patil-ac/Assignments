#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


inline double distanceBetween(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

inline double toRadians(double degrees){
    const double PI = 3.14;
    return degrees * (PI / 180.0);
}

inline double clamp(double value, double minVal, double maxVal){

    if (value < minVal){
        return minVal;
    }
    else if (value > maxVal){
        return maxVal;
    }
    else {
        return value;
    }
}

inline bool isInSafeZone(double x, double y, double cx, double cy, double radius){
    double distance = distanceBetween(x, y, cx, cy);
    return distance <= radius;
}


int main(){
    
    double homeX = 0.0;
    double homeY = 0.0;

    double safeRadius = 50.0;

    double waypointX[] = {30.0, 10.0, 60.0};
    double waypointY[] = {40.0, 20.0, 80.0};


    cout << fixed << setprecision(2);

    for (int i = 0; i < 3; i++){

        double distance = distanceBetween(homeX, homeY, waypointX[i], waypointY[i]);

        bool safe = isInSafeZone(waypointX[i], waypointY[i], homeX, homeY, safeRadius);

        cout << "Waypoint " << i + 1 << " : (" << waypointX[i] << ", " << waypointY[i] << ")" << endl;

        cout << "Distance from Home : " << distance << " units" << endl;

        cout << "Inside Safe Zone : " << (safe ? "Yes" : "No") << endl;

        cout << endl;
    }

    double degrees = 90.0;

    cout << "90 degrees in radians : " << toRadians(degrees) << endl;

    double value = 75.0;

    cout << "Clamped value : " << clamp(value, 0.0, 50.0) << endl;

    
    return 0;
}