#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Employee{

private:

    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:

    Employee(){

        empId = 1001 + employeeCount;
        name = "";
        department = "";
        grade = ' ';
        basicSalary = 0;
        isActive = true;

        employeeCount++;
    }

    bool setName(string newName){

        if (newName.empty()){

            cout << "ERROR: Name cannot be empty." << endl;
            return false;
        }

        name = newName;
        return true;
    }

    bool setDepartment(string newDepartment){

        if (newDepartment != "Engineering" && newDepartment != "HR" && newDepartment != "Finance" && newDepartment != "Operations"){

            cout << "ERROR: '" << newDepartment << "' is not a registered department." << endl;
            return false;
        }

        department = newDepartment;
        return true;
    }

    bool setGrade(char newGrade){

        if (newGrade != 'A' && newGrade != 'B' && newGrade != 'C' && newGrade != 'D'){

            cout << "ERROR: Invalid grade '" << newGrade << "'. Accepted values: A, B, C, D." << endl;
            return false;
        }

        grade = newGrade;
        return true;
    }

    bool setBasicSalary(double salary){

        if (salary <= 10000 || salary >= 500000){

            cout << "ERROR: Salary must be between Rs.10,000 " << "and Rs.5,00,000. Value rejected." << endl;
            return false;
        }

        basicSalary = salary;
        return true;
    }


    void deactivate(){
        isActive = false;
    }

    int getEmpId() const {
        return empId;
    }

    string getName() const {
        return name;
    }

    string getDepartment() const {
        return department;
    }

    char getGrade() const {
        return grade;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    bool getIsActive() const {
        return isActive;
    }

    double computeAllowances() const {

        double percentage = 0;

        switch (grade) {

            case 'A':
                percentage = 40;
                break;

            case 'B':
                percentage = 30;
                break;

            case 'C':
                percentage = 20;
                break;

            case 'D':
                percentage = 10;
                break;
        }

        return basicSalary * percentage / 100;
    }

    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }

    double computeTax() const {
        double gross = computeGrossSalary();

        if (gross <= 50000){
            return 0;
        }
        else if (gross <= 100000){
            return (gross - 50000) * 0.10;
        }
        else {
            return 5000 + (gross - 100000) * 0.20;
        }
    }

    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }


    void printPayslip() const {

        double allowance = computeAllowances();
        double gross = computeGrossSalary();
        double tax = computeTax();
        double net = computeNetSalary();

        double allowancePercentage = 0;

        switch (grade) {

            case 'A':
                allowancePercentage = 40;
                break;

            case 'B':
                allowancePercentage = 30;
                break;

            case 'C':
                allowancePercentage = 20;
                break;

            case 'D':
                allowancePercentage = 10;
                break;
        }


        cout << "============================================" << endl;
        cout << " EMPLOYEE PAYSLIP - AUG 2026" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID       : " << empId << endl;
        cout << "Name         : " << name << endl;
        cout << "Department   : " << department << endl;
        cout << "Grade        : " << grade << endl;

        cout << "Status       : " << (isActive ? "Active" : "Inactive") << endl;

        cout << "--------------------------------------------" << endl;

        cout << fixed << setprecision(2);

        cout << "Basic Salary : Rs. " << basicSalary << endl;

        cout << "Allowances (" << allowancePercentage << "%) : Rs. " << allowance << endl;

        cout << "Gross Salary : Rs. " << gross << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction : Rs. " << tax << endl;
        cout << "Net Salary   : Rs. " << net << endl;

        cout << "============================================" << endl;
    }


    void acceptDetails(){

        string inputName;
        string inputDepartment;
        char inputGrade;
        double inputSalary;


        do {
            cout << "Enter name: ";
            getline(cin >> ws, inputName);

        } while (!setName(inputName));


        do {
            cout << "Enter department: ";
            getline(cin >> ws, inputDepartment);

        } while (!setDepartment(inputDepartment));


        do {
            cout << "Enter grade: ";
            cin >> inputGrade;

        } while (!setGrade(inputGrade));


        do {
            cout << "Enter basic salary: ";
            cin >> inputSalary;

        } while (!setBasicSalary(inputSalary));
    }


    static int getEmployeeCount(){
        return employeeCount;
    }
};


int Employee::employeeCount = 0;

struct Layout1 {
    char c1;
    int i;
    char c2;
};

struct Layout2 {
    int i;
    char c1;
    char c2;
};


int main(){
    
    Employee e1;

    Employee* e2 = new Employee();
    Employee* e3 = new Employee();


    cout << "\nEnter details for Employee 1\n";
    e1.acceptDetails();

    cout << "\nEnter details for Employee 2\n";
    e2->acceptDetails();

    cout << "\nEnter details for Employee 3\n";
    e3->acceptDetails();

    cout << "\n\n";
    e1.printPayslip();

    cout << "\n";
    e2->printPayslip();

    cout << "\n";
    e3->printPayslip();


    e3->deactivate();


    if (!e3->getIsActive()){
        cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
    }


    cout << "\nTotal Employees : " << Employee::getEmployeeCount() << endl;


    cout << "\n--- Struct Padding Bonus ---" << endl;

    cout << "Size of Layout1 : " << sizeof(Layout1) << " bytes" << endl;

    cout << "Size of Layout2 : " << sizeof(Layout2) << " bytes" << endl;


    delete e2;
    delete e3;

    return 0;
}