#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int employeeId;
    static int totalEmployees; // Static member data

public:
    // Constructors
    Employee() : name(""), employeeId(0) {
        totalEmployees++;
    }

    Employee(const string& empName, int empId) : name(empName), employeeId(empId) {
        totalEmployees++;
    }

    // Destructor
    ~Employee() {
        totalEmployees--;
    }

    // Inline function to get the employee name
    inline string getName() const {
        return name;
    }

    // Inline function to get the employee ID
    inline int getEmployeeId() const {
        return employeeId;
    }

    // Friend function to display employee details
    friend void displayEmployeeDetails(const Employee& emp);

    // Function overloading for setting employee details
    void setDetails(const string& empName, int empId) {
        name = empName;
        employeeId = empId;
    }

    // Static member function to get the total number of employees
    static int getTotalEmployees() {
        return totalEmployees;
    }

    // Operator overloading for the << operator to display employee details
    friend ostream& operator<<(ostream& os, const Employee& emp);

    // Operator overloading for the == operator to compare employees
    bool operator==(const Employee& other) const {
        return (name == other.name) && (employeeId == other.employeeId);
    }
};

// Definition of static member data
int Employee::totalEmployees = 0;

// Friend function to display employee details
void displayEmployeeDetails(const Employee& emp) {
    cout << "Employee Name: " << emp.name << endl;
    cout << "Employee ID: " << emp.employeeId << endl;
}

// Operator overloading for the << operator to display employee details
ostream& operator<<(ostream& os, const Employee& emp) {
    os << "Employee Name: " << emp.name << endl;
    os << "Employee ID: " << emp.employeeId << endl;
    return os;
}

int main() {
    // Taking user input to create and set details for employee objects
    string name;
    int empId;

    cout << "Enter details for Employee 1:" << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "Employee ID: ";
    cin >> empId;
    cin.ignore(); // Ignore the newline character in the input buffer

    Employee emp1(name, empId);

    cout << "Enter details for Employee 2:" << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "Employee ID: ";
    cin >> empId;
    cin.ignore(); // Ignore the newline character in the input buffer

    Employee emp2(name, empId);

    // Displaying employee details using operator overloading
    cout << "Details for Employee 1:" << endl;
    cout << emp1;

    cout << "Details for Employee 2:" << endl;
    cout << emp2;

    // Using operator overloading to compare employees
    if (emp1 == emp2) {
        cout << "Employees are the same." << endl;
    } else {
        cout << "Employees are different." << endl;
    }

    // Accessing static member function
    cout << "Total Employees: " << Employee::getTotalEmployees() << endl;

    return 0;
}
