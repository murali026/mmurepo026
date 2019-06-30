#ifndef ISORT_H_
#define ISORT_H_
#include"swap.h"

template <class Iter>
void isort(Iter start, Iter end);

/* This template instantiation requires Iter to support decrement operator(--), increment operator(++), dereference operator(*), less than operator and also swap template 
*/
template <class Iter>
void isort(Iter start, Iter end) {
    for(Iter cur = start; cur != end; ++cur) {
        int c1 = 1;
        //cout << __func__ << ":" << __LINE__ << ": ExternalCount:"<< c1 << endl;
        Iter y = cur;
        Iter x = cur;
        --x;
        while((y != start) && (*y < *x)) {
            int c2 = 1;
            //cout << __func__ << ":" << __LINE__ << ": InternalCount:"<< c2 << endl;
            swap(*y, *x);
            --x;
            --y;
            c2++;
        }
        c1++;
    }
}
#endif
