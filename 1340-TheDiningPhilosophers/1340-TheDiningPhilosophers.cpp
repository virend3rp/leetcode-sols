// Last updated: 4/24/2026, 10:09:49 PM
#include <mutex>
#include <condition_variable>
#include <functional>
class Semaphore{
public:
    Semaphore(){}
    Semaphore(int c): count(c){};

    void setCount(int a){
        count=a;
    }
    inline void signal(){
        unique_lock<mutex> lock(m);
        count++;
        if(count<=0){
            cv.notify_one();
        }
    }
    inline void wait(){
        unique_lock<mutex> lock(m);
        count--;
        if(count<0){
            cv.wait(lock);
        }
    }
private:
    mutex m;
    condition_variable cv;
    int count;    
};
class DiningPhilosophers {
    Semaphore fork[5];
    mutex m,l;
private:
    condition_variable cv;
    int count;
public:
    DiningPhilosophers() {
        for(int i=0;i<5;i++){
            fork[i].setCount(1);
        }   
    }
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		{
            lock_guard lock(m);
            fork[(philosopher+1)%5].wait();
            fork[philosopher].wait();
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        fork[(philosopher+1)%5].signal();
        putRightFork();
        fork[philosopher].signal();
    }
};