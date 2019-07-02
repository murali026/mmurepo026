#ifndef PRINTSEQ_H_
#define PRINTSEQ_H_
template <class Iter> void printSequence(Iter begin, Iter end);

/* Requirements for this template instantiation is Iter must support operators !=, *(deference) and ++(increment) operator.
*/
template <class Iter> void printSequence(Iter begin, Iter end) {
    while(begin != end) {
        std::cout << *begin;
        std::cout << ' ';
        ++begin;
    }
};
#endif
