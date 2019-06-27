#include"student.h"

Student::Student():
    _firstName(""),
    _lastName(""),
    _score(0),
    _grade(' ') {
}

Student::Student(std::string fname, std::string lname, int score):
    _firstName(fname),
    _lastName(lname) {
    setTestScore(score);
}

string Student::firstName() const {
    return _firstName;
}

string Student::lastName() const {
    return _lastName;
}

int Student::testScore() const {
    return _score;
}

char Student::testGrade() const {
    return _grade;
};

void Student::setName(const std::string& fname, const std::string& lname) {
    _firstName = fname;
    _lastName = lname;
}

void Student::setTestScore(int testScore) {
    _score = testScore;
    if(_score >= 90) {
        _grade = 'A';
    } else if(_score >= 80) {
        _grade = 'B';
    } else if(_score >= 70) {
        _grade = 'C';
    } else if(_score >= 60) {
        _grade = 'D';
    } else if(_score >= 50) {
        _grade = 'E';
    } else {
        _grade = 'F';
    }
}

bool Student::operator==(const Student& rhs) const {
    return _firstName == rhs._firstName && _lastName == rhs._lastName;
}

bool Student::operator!=(const Student& rhs) const {
    return !(*this == rhs);
}

bool Student::operator>=(const Student& rhs) const {
    return !(*this < rhs);
}

bool Student::operator<=(const Student& rhs) const {
    return !(*this > rhs); 
}

bool Student::operator>(const Student& rhs) const {
    return (*this != rhs) && !(*this < rhs);
}

bool Student::operator<(const Student& rhs) const {
    if(_lastName < rhs._lastName) {
        return true;
    } else if(_firstName < rhs._firstName) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& lhs, const Student& rhs) {
    lhs << rhs.firstName() << " " << rhs.lastName() << " " << rhs.testScore() << " " << rhs.testGrade() << endl;
}

std::istream& operator>>(std::istream& lhs, Student& rhs) {
    int testScore;
    string fName;
    string lName;
    //lhs >> rhs._firstName >> rhs._lastName >> testScore;
    lhs >> fName >> lName >> testScore;
    rhs.setName(fName, lName);
    rhs.setTestScore(testScore);
    return lhs;
}

void printFullName(const Student& s) {
    cout << s.firstName() << " " << s.lastName() << endl;
}

void printTestResults(const Student& s) {
    cout << s.testScore() << " " << s.testGrade() << endl;
}

void printArray(Student* start, Student* end) {
    for(Student* cur=start; cur != end; cur++) {
        //cout << cur->firstName() << " " << cur->lastName() << " " << cur->testScore() << " " << cur->testGrade() << endl;
        cout << *cur;
    }
}

int main() {
    Student s;
    s.setName("Murali", "M");
    s.setTestScore(80);
    cout << s.firstName() << endl;
    printFullName(s);
    printTestResults(s);
    int classSize = 5;
    Student students[classSize];
    for (int i=0; i<classSize; i++) {
        string fName;
        string lName;
        int tScore;
        cout << "Enter First Name, Last Name, and test score \n";
        //cin >> fName >> lName >> tScore;
        cin >> students[i];
        students[i].setName(fName, lName);
        students[i].setTestScore(tScore);
    }
    printArray(students, students+classSize);
    return 1;
}
