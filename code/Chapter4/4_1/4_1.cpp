#include <iostream>
using namespace std;

class Clock {
public:
    void setTime(int newH = 0, int newM = 0, int newS = 0);
    void showTime();
private:
    int hour, minute, second;
};

void Clock::setTime(int newH, int newM, int newS) {
    hour = newH;
    minute = newM;
    second = newS;
}

void Clock::showTime() {
    cout << hour << ":" << minute << ":" << second << endl;
}

int main() {
    Clock myClock;
    cout << "First time set and output:" << endl;
    myClock.setTime();
    myClock.showTime();
    cout << "Second time set and output:" << endl;
    myClock.setTime(8, 30, 30);
    myClock.showTime();
    return 0;
}
