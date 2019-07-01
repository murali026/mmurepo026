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

#endif
