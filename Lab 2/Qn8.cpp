#include <iostream>
#include <cmath>
using namespace std;

class DateTime {
private:
    int days, hours, minutes;

public:
    DateTime(int d = 0, int h = 0, int m = 0) : days(d), hours(h), minutes(m) {}

    int getTotalHours() const {
        return days * 24 + hours + (minutes > 0 ? 1 : 0);
    }

    int getHours() const{
        return hours;
    }

    void setHours(int h) {
        hours = h;
    }

    void operator++() {
        hours++;
        if (hours >= 24) {
            days++;
            hours = 0;
        }
    }

    void operator--() {
        if (hours > 0) {
            hours--;
        } else {
            if (days > 0) {
                days--;
                hours = 23;
            }
        }
    }
};

class ParkingGarage {
private:
    double totalEarnings;
    int carCount;

public:
    ParkingGarage() : totalEarnings(0), carCount(0) {}

    void enter(DateTime enterTime) {
        ++carCount;
    }

    void leave(DateTime enterTime, DateTime leaveTime) {
        --carCount;

        int duration = leaveTime.getTotalHours() - enterTime.getTotalHours();

        double charge = 0;
        if (duration <= 3) {
            charge = 2.0;
        } else if (duration <= 24) {
            charge = 2.0 + 0.5 * (duration - 3);
        } else {
            charge = 8.0 * ceil(duration / 24.0);
        }

        totalEarnings += charge;

        cout << "Parking charge: $" << charge << endl;
    }

    void displayEarnings() const {
        cout << "Total earnings: $" << totalEarnings << endl;
    }

    int getCarCount() const {
        return carCount;
    }
};

int main() {
    ParkingGarage garage;

    DateTime enterTime(0, 10, 15); 
    DateTime leaveTime(1, 13, 30); 
    DateTime enterTime1(0, 10, 15);
    DateTime leaveTime1(1, 13, 30);

    garage.enter(enterTime);
    garage.leave(enterTime, leaveTime);
    garage.enter(enterTime1);
    garage.leave(enterTime1, leaveTime1);

    garage.displayEarnings();

    return 0;
}