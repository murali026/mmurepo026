#ifndef STUDENT_PREDICATES_H
#define STUDENT_PREDICATES_H

struct LessByFirstName {
    bool operator()(const Student& a, const Student& b) const;
};

struct GreaterByFirstName {
    bool operator()(const Student& a, const Student& b) const;
};

struct LessByTestScore {
    bool operator()(const Student& a, const Student& b) const;
};

struct GreaterByTestScore {
    bool operator()(const Student& a, const Student& b) const;
};

inline bool LessByTestScore::operator()(const Student& a, const Student& b) const {
    return a.testScore() < b.testScore();
};

inline bool GreaterByTestScore::operator()(const Student& a, const Student& b) const {
    return a.testScore() > b.testScore();
};

inline bool LessByFirstName::operator()(const Student& a, const Student& b) const {
    return a.firstName() < b.firstName();
}

inline bool GreaterByFirstName::operator()(const Student& a, const Student& b) const {
    return a.firstName() > b.firstName();
}
#endif
