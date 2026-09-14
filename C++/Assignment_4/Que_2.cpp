#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Vehicle {

protected:

    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:

    Vehicle(const string& reg, const string& owner, int year, double km) {
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;

        cout << "[Vehicle Constructor] " << registrationNo << " : " << ownerName << endl;
    }

    virtual string vehicleType() const = 0;

    virtual double fuelCost(double kmToTravel) const = 0;

    virtual void describe() const {

        cout << "Registration No : " << registrationNo << endl;
        cout << "Owner Name       : " << ownerName << endl;
        cout << "Year             : " << yearOfManufacture << endl;
        cout << "KM Driven        : " << kmDriven << endl;
        cout << "Vehicle Type     : " << vehicleType() << endl;
    }

    virtual ~Vehicle() {
        cout << "[Vehicle Destructor] " << registrationNo << endl;
    }

    double getKmDriven() const {
        return kmDriven;
    }

    string getRegNo() const {
        return registrationNo;
    }

    string getOwnerName() const {
        return ownerName;
    }
};

class Car : public Vehicle {

private:

    string fuelType;
    double mileageKmpl;

public:

    Car(const string& reg, const string& owner, int year, double km, const string& fuel, double mileage) : Vehicle(reg, owner, year, km) {
        fuelType = fuel;
        mileageKmpl = mileage;

        cout << "[Car Constructor] " << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {
        double fuelPrice;

        if (fuelType == "Petrol") {
            fuelPrice = 106.00;
        }
        else {
            fuelPrice = 93.00;
        }

        return (kmToTravel / mileageKmpl) * fuelPrice;
    }

    string vehicleType() const override {
        return "Car";
    }

    void describe() const override {
        Vehicle::describe();

        cout << "Fuel Type        : " << fuelType << endl;

        cout << "Mileage          : " << mileageKmpl << " km/l" << endl;
    }

    ~Car() override {
        cout << "[Car Destructor] " << registrationNo << endl;
    }
};

class Truck : public Vehicle {

protected:

    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& reg,const string& owner,int year,double km,double payload,double efficiency): Vehicle(reg, owner, year, km) {
        payloadCapacityTons = payload;
        fuelEfficiencyKmpl = efficiency;

        cout << "[Truck Constructor] " << registrationNo << endl;
    }

    virtual double fuelCost(double kmToTravel) const override {
        
        double adjustedEfficiency =fuelEfficiencyKmpl *(1 - 0.05 * payloadCapacityTons);

        double fuelUsed = kmToTravel / adjustedEfficiency;

        return fuelUsed * 93.00;
    }

    string vehicleType() const override {
        return "Truck";
    }

    void describe() const override {
        Vehicle::describe();

        cout << "Payload Capacity : " << payloadCapacityTons << " tons" << endl;

        cout << "Fuel Efficiency  : " << fuelEfficiencyKmpl << " km/l" << endl;
    }

    ~Truck() override {
        cout << "[Truck Destructor] " << registrationNo << endl;
    }
};

class ElectricTruck : public Truck {

private:

    double batteryCapacityKWh;
    double rangePerChargeKm;

public:

    ElectricTruck(const string& reg,const string& owner, int year,double km,double payload,double efficiency,double batteryCapacity,double rangePerCharge): Truck(reg, owner, year, km, payload, efficiency) {

        batteryCapacityKWh = batteryCapacity;
        rangePerChargeKm = rangePerCharge;

        cout << "[ElectricTruck Constructor] " << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {

        double electricityUsed =(kmToTravel / rangePerChargeKm)* batteryCapacityKWh;
        return electricityUsed * 9.50;
    }

    string vehicleType() const override {
        return "Electric Truck";
    }

    void describe() const override {
        Vehicle::describe();

        cout << "Payload Capacity : " << payloadCapacityTons << " tons" << endl;

        cout << "Battery Capacity : " << batteryCapacityKWh << " kWh" << endl;

        cout << "Range Per Charge : " << rangePerChargeKm << " km" << endl;
    }

    double getBatteryCapacity() const {
        return batteryCapacityKWh;
    }

    double getRangePerCharge() const {
        return rangePerChargeKm;
    }

    ~ElectricTruck() override {
        cout << "[ElectricTruck Destructor] " << registrationNo << endl;
    }
};

class Van : public Vehicle {

private:

    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& reg, const string& owner, int year, double km, int seating, double mileage) : Vehicle(reg, owner, year, km) {

        seatingCapacity = seating;
        mileageKmpl = mileage;
        cout << "[Van Constructor] " << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {
        return (kmToTravel / mileageKmpl) * 106.00;
    }

    string vehicleType() const override {
        return "Van";
    }

    void describe() const override {
        Vehicle::describe();

        cout << "Seating Capacity : " << seatingCapacity << endl;

        cout << "Mileage          : " << mileageKmpl << " km/l" << endl;
    }

    ~Van() override {
        cout << "[Van Destructor] " << registrationNo << endl;
    }
};

void printFleetReport(const vector<Vehicle*>& fleet, double tripKm) 
    cout << "\n=============================================\n";
    cout << " FLEET REPORT - Trip Distance: " << tripKm << " km\n";
    cout << "=============================================\n";

    cout << left << setw(12) << "Reg" << setw(20) << "Type" << setw(20) << "Owner << setw(12) << "Km Driven" << endl;

    cout << "------------------------------------------------------------\n";

    for (Vehicle* vehicle : fleet) {
        cout << left << setw(12) << vehicle->getRegNo() << setw(20) << vehicle->vehicleType() << setw(20) << vehicle->getOwnerName() << setw(12) << vehicle->getKmDriven() << endl;
    }

    cout << "\n=============================================\n";
    cout << " FUEL / CHARGE COST ESTIMATE\n";
    cout << "=============================================\n";

    double minimumCost = 0;
    Vehicle* mostEfficient = nullptr;

    for (Vehicle* vehicle : fleet) {
        double cost = vehicle->fuelCost(tripKm);

        cout << vehicle->getRegNo() << " (" << vehicle->vehicleType() << ")" << " : Rs. " << fixed << setprecision(2) << cost;

        ElectricTruck* electricVehicle = dynamic_cast<ElectricTruck*>(vehicle);

        if (electricVehicle != nullptr) {
            cout << " [Battery: " << electricVehicle->getBatteryCapacity() << " kWh available]";
        }

        cout << endl;

        if (mostEfficient == nullptr ||
            cost < minimumCost) {
            minimumCost = cost;
            mostEfficient = vehicle;
        }
    }

    cout << "\n=============================================\n";

    if (mostEfficient != nullptr) {

        cout << "Most Efficient Vehicle: " << mostEfficient->getRegNo() << " (" << mostEfficient->vehicleType() << ")" << " - Rs. " << fixed << setprecision(2) << minimumCost << " for " << tripKm << " km" << endl;
    }
}


int main()
{
    cout << fixed << setprecision(2);

    // ==================================================
    // PART B
    // Constructor / Destructor Execution Order
    // ==================================================

    cout << "\n=============================================\n";
    cout << " PART B - CONSTRUCTOR / DESTRUCTOR ORDER\n";
    cout << "=============================================\n";

    {
        ElectricTruck et("V-ET001", "Green Logistics", 2024, 10000, 4, 8, 500, 400);
        cout << "...scope ends..." << endl;
    }

    // ==================================================
    // PART A + PART C
    // Create vehicles dynamically
    // ==================================================

    cout << "\n=============================================\n";
    cout << " PART C - POLYMORPHIC FLEET\n";
    cout << "=============================================\n";

    vector<Vehicle*> fleet;

    fleet.push_back(new Car("KA01AA001", "Ramesh Kumar", 2022, 45200, "Petrol", 15));

    fleet.push_back(new Car("MH02AA002", "Priya Shah", 2023, 32000, "Petrol", 18));

    fleet.push_back(new Truck("MH04BB002", "Shyam Logistics", 2020, 123500, 5, 9));

    fleet.push_back(new ElectricTruck("GJ07CC003", "Green Fleet Co", 2024, 89000, 2, 8, 500, 400));

    fleet.push_back( new Van("DL08DD004", "City Transport", 2021, 67800, 8, 12));


    // ==================================================
    // Generate Fleet Report
    // ==================================================

    printFleetReport(fleet, 200);

    // ==================================================
    // Cleanup
    // ==================================================

    cout << "\n=============================================\n";
    cout << " CLEANUP\n";
    cout << "=============================================\n";

    for (Vehicle* vehicle : fleet) {
        delete vehicle;
    }

    fleet.clear();

    cout << "\nAll heap-allocated vehicles deleted.\n";

    return 0;
}