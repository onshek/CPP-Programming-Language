#include <iostream>
using namespace std;

class Clock {
private:
	int hour, minute, second;
public:
	Clock(int hour = 0, int minute = 0, int second = 0);
	void showTime() const;
	Clock& operator++ ();
	Clock operator++ (int);
};

Clock::Clock(int hour, int minute, int second) {
	if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0<= second && second < 60) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	else {
		cout << "Time error!" << endl;
	}
}

void Clock::showTime() const {
	cout << hour << ":" << minute << ":" << second << endl;
}

Clock& Clock::operator++() {
	second++;
	if (second >= 60) {
		second -= 60;
		minute++;
		if (minute >= 60) {
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}

Clock Clock::operator++(int) {
	Clock old = *this;
	++(*this);
	return old;
}

int main() {
	Clock myClock(23, 59, 59);
	cout << "First time output: ";
	myClock.showTime();
	cout << "Show myClock++: ";
	(myClock++).showTime();
	cout << "Show ++myClock: ";
	(++myClock).showTime();
	return 0;
}