#include<iostream>

using namespace std;

class person {
    char name[30];
    int age;
    int id;

    public:
        void get_Data(){
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter id: ";
            cin >> id;
        }

        void show_Data(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Id: " << id << endl;
        }
};

class employee : public person{
    char designation[30];

    protected:
        float basicSal;
        int totOvertime;
        int hourlyRate;

    public:
        void get_Data(){
            person::get_Data();
            cout << "Enter employee designation: ";
            cin >> designation;
            cout << "Enter the basic salary: ";
            cin >> basicSal;
            cout << "Enter the total overtime in a month in hours: ";
            cin >> totOvertime;
            cout << "Enter the hourly rate: ";
            cin >> hourlyRate;
        }

        void show_Data(){
            person :: show_Data();
            cout << "Designation: " << designation << endl;
            cout << "Basic Salary: " << basicSal << endl;
        }
};

class computedsalary : public employee {
    float totalSal;

    public:
        void get_Data(){
            employee :: get_Data();
            calculate();
        }

        void calculate(){
            totalSal = basicSal + totOvertime * hourlyRate;
        }

        float getTotal(){
            return totalSal;
        }

        void show_Data(){
            employee :: show_Data();
            cout << "Total Salary: " << totalSal << endl;
        }
};

int main(){
    computedsalary total;
    total.get_Data();
    total.show_Data();
    return 0;
}