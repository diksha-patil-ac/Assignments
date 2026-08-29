#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    const int floors = 3;
    const int rooms = 3;

    double temperature[floors][rooms];

    for (int i = 0; i < floors; i++){

        for (int j = 0; j < rooms; j++){

            cout << "Enter temperature for Floor " << i + 1 << ", Room " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }

    cout << "\n";
    cout << "  " << endl;

    cout << left << setw(10) << " " << setw(12) << "Room 1" << setw(12) << "Room 2" << setw(12) << "Room 3" << endl;
    cout << "  " << endl;

    cout << fixed << setprecision(1);

    for (int i = 0; i < floors; i++){
        cout << left << setw(10) << "Floor " << i + 1;

        for (int j = 0; j < rooms; j++){
            cout << setw(12) << temperature[i][j];
        }
        
        cout << endl;
    }

    cout << "  " << endl;

    double hottest = temperature[0][0];
    int hottestFloor = 0;
    int hottestRoom = 0;

    for (int i = 0; i < floors; i++){
        for (int j = 0; j < rooms; j++){

            if (temperature[i][j] > hottest){

                hottest = temperature[i][j];
                hottestFloor = i;
                hottestRoom = j;
            }
        }
    }

    double highestAverage = 0;
    int hottestFloorNumber = 0;

    for (int i = 0; i < floors; i++){
        double sum = 0;

        for (int j = 0; j < rooms; j++){
            sum += temperature[i][j];
        }

        double average = sum / rooms;

        if (i == 0 || average > highestAverage){
            highestAverage = average;
            hottestFloorNumber = i;
        }
    }

    int warningRooms = 0;

    for (int i = 0; i < floors; i++){
        for (int j = 0; j < rooms; j++){

            if (temperature[i][j] >= 30.0){
                warningRooms++;
            }
        }
    }

    cout << "Hottest Room : Floor " << hottestFloor + 1 << ", Room " << hottestRoom + 1 << " -> " << fixed << setprecision(1) << hottest << "°C" << endl;

    cout << "Hottest Floor : Floor " << hottestFloorNumber + 1 << " (avg " << fixed << setprecision(2) << highestAverage << "°C)" << endl;

    cout << "Rooms at WARNING or above : " << warningRooms << endl;

    return 0;
}