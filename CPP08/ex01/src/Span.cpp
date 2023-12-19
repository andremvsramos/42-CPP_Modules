/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:59:00 by andvieir          #+#    #+#             */
/*   Updated: 2023/12/19 18:12:39 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Span.hpp"

/* ===================== Orthodox Canonical Form ===================== */

Span::Span () : N(0) {}

Span::Span (const Span& original) :
    N(original.N), _values(original._values) {}

Span &Span::operator=(const Span& original) {
    if (this == &original)
        return (*this);
    N = original.N;
    _values = original._values;
    return (*this);
}

Span::~Span () {}


/* ===================== Constructors ===================== */

Span::Span(unsigned int N) : N(N) {}

/* ===================== Getter Functions ===================== */

unsigned int Span::getN() {
    return (N);
}

size_t  Span::getVectorSize() {
    return (_values.size());
}

/* ===================== Member Functions ===================== */

void Span::addNumber() {
    _values.size() < N ? _values.push_back(rand()%10000)
        : throw Span::ElementLimitReachedException();
}

void Span::shortestSpan() {
    if (_values.size() < 2) throw NoSpanException();
    std::vector<int> sortedValues = _values;
    std::sort(sortedValues.begin(), sortedValues.end());
    int minDiff = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedValues.size(); i++) {
        int diff = sortedValues[i] - sortedValues[i - 1];
        minDiff = std::min(minDiff, diff);
    }
    std::cout << "Shortest span: " << minDiff << std::endl;
}

void Span::longestSpan() {
    if (_values.size() < 2) throw NoSpanException();
    int max = *std::max_element(_values.begin(), _values.end());
    int min = *std::min_element(_values.begin(), _values.end());
    std::cout << "Longest span: " << max - min << std::endl;
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t count = std::distance(begin, end);
    if (_values.size() + count > getN()) throw ElementLimitReachedException();
    _values.insert(_values.end(), begin, end);
}

void Span::fillSpan() {
    _values.resize(N);
    std::generate(_values.begin(), _values.end(), RandomNumberGenerator);
}

void Span::printVector() {
    std::vector<int>::iterator it;
    for (it = _values.begin(); it < _values.end(); it++) {
        std::cout << *it << std::endl;
    }
}

/* ===================== Exceptions ===================== */

const char *Span::ElementLimitReachedException::what() const throw() {
    return ("Element Limit Reached... Aborting");
}

const char *Span::NoSpanException::what() const throw() {
    return ("No span in vector");
}

/* ===================== Non Member Functions ===================== */

int RandomNumberGenerator() {
    return (rand()%10000);
}
