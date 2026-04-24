// Last updated: 4/24/2026, 10:08:39 PM
class ParkingSystem {
public:
    int car1, car2, car3;

    ParkingSystem(int big, int medium, int small) {
        car1 = big;
        car2 = medium;
        car3 = small;
    }

    bool addCar(int carType) {
        if (carType == 1) {
            if (car1 > 0) {
                car1--;
                return true;
            } else {
                return false;
            }
        } else if (carType == 2) {
            if (car2 > 0) {
                car2--;
                return true;
            } else {
                return false;
            }
        } else {
            if (car3 > 0) {
                car3--;
                return true;
            } else {
                return false;
            }
        }
    }
};
