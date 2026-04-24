// Last updated: 4/24/2026, 10:10:15 PM
#include <condition_variable>
#include <mutex>
class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool turn;
public:
    FooBar(int n) {
        this->n = n;
        turn=0;
    }

    void foo(function<void()> printFoo) {
        unique_lock lock(m);
        for (int i = 0; i < n; i++) {
            while(turn==1){
                cv.wait(lock);
            }
        	printFoo();
            turn=1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock lock(m);
        for (int i = 0; i < n; i++) {
            while(turn==0){
                cv.wait(lock);
            }
        	printBar();
            turn=0;
            cv.notify_all();
        }
    }
};