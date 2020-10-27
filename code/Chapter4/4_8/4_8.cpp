#include <iostream>
#include <iostream>
using namespace std;

class ExamInfo {
public:
    ExamInfo(string name, char grate)
        : name(name), mode(GRADE), grade(grate) {}
    ExamInfo(string name, bool pass)
        : name(name), mode(PASS), pass(pass) {}
    ExamInfo(string name, int percent)
        : name(name), mode(PERCENTAGE), percent(percent) {}
    void show();
private:
    string name;
    enum {
        GRADE,
        PASS,
        PERCENTAGE
    } mode;
    union {
        char grade;
        bool pass;
        int percent;
    };
};

void ExamInfo::show() {
    cout << name << ": ";
    switch (mode) {
    case GRADE:
        cout << grade;
        break;
    case PASS:
        cout << (pass ? "PASS" : "FAIL");
        break;
    case PERCENTAGE:
        cout << percent;
        break;
    }
    cout << endl;
}

int main() {
    ExamInfo course1("English", 'B');
    ExamInfo course2("Calculus", true);
    ExamInfo course3("C++Programming", 85);
    course1.show();
    course2.show();
    course3.show();
    return 0;
}
