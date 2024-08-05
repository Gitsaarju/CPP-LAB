
#include <iostream>
#include <cstring>

using namespace std;

class Inventory {
    int quant;     // number on hand
    int reorder;   // reorder quantity
    double price;  // price per unit
    char *des; // description of item
    public:
        Inventory(){}
        Inventory(int q, int r, double p, char *d) : quant(q), reorder(r), price(p){
            des = new char[strlen(d) + 1];
            strcpy(des, d);
        }
        ~Inventory(){
            delete[] des;
        };
        void print(){
            cout<< "Quantity: " << quant << endl;
            cout << "Reorder: " << reorder << endl;
            cout << "Price: " << price << endl;
            cout << "Description: " << des<< endl;
        }
};

class Auto : public Inventory {
    char * manufacturer;
    public:
        Auto (int q, int r, double p, char * d, char * man) : Inventory(q, r ,p, d){
            manufacturer = new char[strlen(man) + 1];
            strcpy(manufacturer, man);
        }
        ~Auto(){
            delete[] manufacturer;
        }

        void print(){
            Inventory :: print();
            cout << "Manufacturer: " << manufacturer << endl;
        }
};

class Transmission : public Inventory {
    char * vendor;
    public:
        Transmission (int q, int r, double p, char * d, char * ven) : Inventory(q, r, p, d){
            vendor = new char[strlen(ven) + 1];
            strcpy(vendor, ven);
        }
        ~ Transmission(){
            delete[] vendor;
        }
        void print(){
            Inventory :: print();
            cout << "Vendor: " << vendor << endl;
        };
};

int main(){
    char desc[] = "Purchased from Aztec Inc.";
    char ven[] = "Aztec Inc.";
    Transmission trans(25, 10, 1789.98 , desc, ven);
    trans.print();
    return 0;
}