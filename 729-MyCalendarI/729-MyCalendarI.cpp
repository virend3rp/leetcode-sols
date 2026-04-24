// Last updated: 4/24/2026, 10:11:53 PM
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto itr = intervals.lower_bound(endTime);
        if (itr == intervals.begin() || (--itr)->second <= startTime) {
            intervals[startTime] = endTime;
            return true;
        }
        return false;
    }
private:
    map<int, int> intervals;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */