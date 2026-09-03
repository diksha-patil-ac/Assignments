#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int n;

    cout << "Enter number of readings: ";
    cin >> n;

    double readings[100];

    for (int i = 0; i < n; i++){
        cout << "Enter reading " << i + 1 << ": ";
        cin >> readings[i];
    }

    cout << endl;
    cout << "Readings entered : " << n << endl;

    int errorCount = 0;

    cout << "Valid readings : ";

    for (int i = 0; i < n; i++){
        if (readings[i] < 0){
            errorCount++;
            continue;
        }
        cout << readings[i] << " ";
    }

    cout << endl;
    cout << "Skipped (errors) : " << errorCount << endl;

    for (int i = 0; i < n; i++){

        if (readings[i] < 0){
            continue;
        }
        if (readings[i] >= 45){
            cout << "First CRITICAL : Index "
                 << i << " -> " << readings[i] << "°C" << endl;
            break;
        }
    }

    double minTemp = 0;
    double maxTemp = 0;
    double sum = 0;

    int validCount = 0;

    int normalCount = 0;
    int warningCount = 0;
    int criticalCount = 0;
    int shutdownCount = 0;

    for (int i = 0; i < n; i++){
        if (readings[i] < 0){
            continue;
        }

        if (validCount == 0){
            minTemp = readings[i];
            maxTemp = readings[i];
        }
        else {
            if (readings[i] < minTemp){
                minTemp = readings[i];
            }

            if (readings[i] > maxTemp){
                maxTemp = readings[i];
            }
        }

        sum = sum + readings[i];
        validCount++;

        if (readings[i] >= 60){
            shutdownCount++;
        }
        else if (readings[i] >= 45){
            criticalCount++;
        }
        else if (readings[i] >= 30){
            warningCount++;
        }
        else {
            normalCount++;
        }
    }

    double average = sum / validCount;

    cout << "Min : " << minTemp << "°C Max : " << maxTemp << "°C Avg : " << average << "°C" << endl;

    cout << "Normal:" << normalCount << " Warning:" << warningCount << " Critical:" << criticalCount << " Shutdown:" << shutdownCount << endl;

    return 0;
}
