#ifndef ISORT_H_
#define ISORT_H_
#include"swap.h"
#include"predicates.h"

template <class Iter, class Predicate>
void isort(Iter start, Iter end, Predicate predicate);

/* This template instantiation requires Iter to support decrement operator(--), increment operator(++), dereference operator(*), less than operator and also swap template 
*/
template <class Iter, class Predicate>
void isort(Iter start, Iter end, Predicate predicate) {
    for(Iter cur = start; cur != end; ++cur) {
        int c1 = 1;
        //cout << __func__ << ":" << __LINE__ << ": ExternalCount:"<< c1 << endl;
        Iter y = cur;
        Iter x = cur;
        --x;
        while((y != start) && predicate(*y, *x)) {
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
