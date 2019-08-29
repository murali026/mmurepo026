#ifndef SWAP_H_
#define SWAP_H_

template <typename T>
void swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
};

#endif
