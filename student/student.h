#include<iostream>
#include<string>
#include"isort.h"
#include"printSequence.h"
#include"swap.h"
using namespace std;

class Student {
public:
    Student();
    Student(std::string fname, std::string lname, int score);
    Student(const Student& src);
    std::string firstName() const;
    std::string lastName() const;
    int testScore() const;
    char testGrade() const;

    void setName(const std::string& fname, const std::string& lname);
    void setTestScore(int testScore);
    Student& operator=(const Student& rhs);
    bool operator==(const Student& rhs) const;
    bool operator!=(const Student& rhs) const;
    bool operator>=(const Student& rhs) const;
    bool operator<=(const Student& rhs) const;
    bool operator>(const Student& rhs) const;
    bool operator<(const Student& rhs) const;
    friend std::istream& operator>>(std::istream& lhs, Student& rhs);

private:
    std::string _firstName;
    std::string _lastName;
    int _score;
    char _grade;
};

std::ostream& operator<<(std::ostream& lhs, const Student& rhs);
void printFullName(const Student& s);
void printTestResults(const Student& s);
