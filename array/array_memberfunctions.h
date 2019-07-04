template <class T, const unsigned int Size>
inline bool Array<T, Size>::empty() const {
    return Size == 0;
};

template <class T, const unsigned int Size>
inline typename Array<T, Size>::size_type Array<T, Size>::size() const {
    return Size;
};

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_iterator Array<T, Size>::begin() const {
};

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_iterator Array<T, Size>::end() const {
};

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_reference Array<T, Size>::front() const {
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_reference Array<T, Size>::back() const {
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::iterator Array<T, Size>::begin() {
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::iterator Array<T, Size>::end() {
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::iterator Array<T, Size>::front() {
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::iterator Array<T, Size>::back() {
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_reference Array<T, Size>::operator[](size_type index) const {
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::reference Array<T, Size>::operator[](size_type index) {
}
