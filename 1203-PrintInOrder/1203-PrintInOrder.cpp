// Last updated: 4/24/2026, 10:10:13 PM
#include <mutex>
#include <condition_variable>
#include <functional>

class Foo {
    std::mutex m;
    std::condition_variable cv;
    int turn;

public:
    Foo(){turn=0;}// Initialize 'turn' in the constructor initializer list.

    void first(function<void()> printFirst) {
        printFirst();
        turn = 1; // Update the turn to indicate the next stage.
        cv.notify_all(); // Notify other threads waiting on the condition variable.
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m); // Lock the mutex.
        while(turn!=1){
            cv.wait(lock);
        }
        printSecond();
        turn = 2; // Update the turn to indicate the next stage.
        cv.notify_all(); // Notify other threads waiting on the condition variable.
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m); // Lock the mutex.
        while(turn!=2){
            cv.wait(lock);
        } 
        printThird();
    }
};
