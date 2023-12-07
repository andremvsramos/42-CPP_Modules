/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:53:22 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/07 18:09:36 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/* ===================== Orthodox Canonical Form ===================== */

template <typename T>
Array<T>::Array () {
    _array = new T[0];
    _size = 0;
}

template <typename T>
Array<T>::Array (const Array& original) {
    _array = new T[original.size()];
    _size = original.size();
    for (unsigned int i = 0; i < size(); i++)
        _array[i] = original._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& original) {
    if (this == &original)
        return (*this);
    if (this)
        delete [] _array;
    _array = new T[original.size()];
    _size = original.size();
    for (unsigned int i = 0; i < size(); i++)
        _array[i] = original._array[i];
    return (*this);
}

template <typename T>
Array<T>::~Array () {
    delete [] _array;
}

/* ===================== Constructors ===================== */

template <typename T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
    _size = n;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = T();
}

/* ===================== Getters / Setters ===================== */

template <typename T>
unsigned int Array<T>::size() const {
    return (_size);
}

/* ===================== Exceptions ===================== */

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return ("Out of bounds");
}

/* ===================== Overloaders ===================== */

template <typename T>
T& Array<T>::operator[](unsigned int index) const {
    if (index >= size())
        throw Array<T>::OutOfBoundsException();
    return (_array[index]);
}

template <typename T>
std::ostream    &operator<<(std::ostream& out, const Array<T>& array) {
    for (unsigned int i = 0; i < array.size(); i++)
        out << array[i] << std::endl;
    out << "size: " << array.size() << std::endl;
    return (out);
}

#endif
