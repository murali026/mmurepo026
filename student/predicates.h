#ifndef PREDICATES_H_
#define PREDICATES_H_

template <class T>
struct Less {
    bool operator()(const T& a, const T&b) {
        return a < b;
    }
};

template <class T>
struct Greater {
    bool operator()(const T& a, const T& b) {
        return a > b;
    }
};

template <class T, class Predicate>
bool isReflexivelyEqual(const T&  a, const T& b, Predicate predicate);

template <class T, class Predicate>
bool isReflexivelyEqual(const T&  a, const T& b, Predicate predicate) {
    return !predicate(a,b) && !predicate(b,a);
};
#endif
