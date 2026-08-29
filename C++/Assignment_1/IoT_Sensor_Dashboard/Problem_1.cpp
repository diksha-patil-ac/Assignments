#include<iostream>
using namespace std;

int main(){

    double temperature;
    int statusCode;
    double fahrenheit;

    cout << "Enter temperature value: " << endl;
    cin >> temperature;

    fahrenheit = (temperature * 9 / 5) + 32;
    cout << "Temperature: " << temperature << char(248) << "C / " << fahrenheit << char(248) << "F" << endl;

    if(temperature < 0){
        statusCode = -1;
        cout << "Status : SENSOR ERROR" << endl;
    }
    else if(temperature < 30){
        statusCode = 0;
        cout << "Status : NORMAL" << endl;
    }
    else if(temperature < 45){
        statusCode = 1;
        cout << "Status : WARNING" << endl;
    }
    else if(temperature < 60){
        statusCode = 2;
        cout << "Status : CRITICAL" << endl;
    }
    else{
        statusCode = 3;
        cout << "Status : SHUTDOWN" << endl;
    }

    switch(statusCode){
        case -1 :
                cout << "Action: Sensor fault-check warning" << endl;
                break;

        case 0 :
                cout << "Action: No action required" << endl;
                break;

        case 1 :
                cout << "Action: Alert sent to supervisor" << endl;
                break;

        case 2 :
                cout << "Action: Cooling system triggered" << endl;
                break;

        case 3 :
                cout << "Action: Emergency shutdown initiated" << endl;
                break;
    }

    cout << "Reading: " << (temperature >= 25 ? "Above Average" : "Below Average") << endl;

        return 0;
}