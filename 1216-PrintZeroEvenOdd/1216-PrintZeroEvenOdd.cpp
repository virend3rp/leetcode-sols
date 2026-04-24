// Last updated: 4/24/2026, 10:10:10 PM
#include <condition_variable>
#include <mutex>
class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
    int i;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn=0;
        i=1;
    }
    void zero(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock lock(m);
            while (turn != 0 && i <= n) {
                cv.wait(lock);
            }
            if (i > n) {
                break;
            }
            printNumber(0);
            turn = (i % 2 == 0) ? 2 : 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock lock(m);
            while (turn != 2 && i <= n) {
                cv.wait(lock);
            }
            if (i > n) {
                break;
            }
            printNumber(i++);
            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock lock(m);
            while (turn != 1 && i <= n) {
                cv.wait(lock);
            }
            if (i > n) {
                break;
            }
            printNumber(i++);
            turn = 0;
            cv.notify_all();
        }
    }
};