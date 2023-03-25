//
//  ECRational.cpp
//  
//
//  Created by Yufeng Wu on 1/7/23.
//

#include "ECRational.h"
#include <iostream>

template <class T>
ECRational<T>::ECRational(const T &numeratorIn, const T &denominatorIn) : numerator(numeratorIn), denominator(denominatorIn) {}

template <class T>
ECRational<T>::ECRational(const ECRational &rhs) {
    this->numerator = rhs.numerator;
    this->denominator = rhs.denominator;
}

template <class T>
ECRational<T>& ECRational<T>::operator=(const ECRational &rhs) {
    this->numerator = rhs.numerator;
    this->denominator = rhs.denominator;
    return *this;
}

template<class T>
ECRational<T> ECRational<T>::operator+(const ECRational &rhs) const {
    T lcd = this->denominator * rhs.denominator;
    T rhsNum = rhs.numerator * this->denominator;
    T lhsNum = this->numerator * rhs.denominator;
    T newNum = rhsNum + lhsNum;
    return (ECRational<T>(newNum, lcd));
}

template <class T>
ECRational<T> ECRational<T>::operator-(const ECRational &rhs) const {
    T lcd = this->denominator * rhs.denominator;
    T rhsNum = rhs.numerator * this->denominator;
    T lhsNum = this->numerator * rhs.denominator;
    T newNum = lhsNum - rhsNum;
    return (ECRational<T>(newNum, lcd));
}

template <class T>
ECRational<T> ECRational<T>::operator*(const ECRational &rhs) const {
    return (ECRational<T>(this->numerator * rhs.numerator, this->denominator * rhs.denominator));
}

template <class T>
ECRational<T> ECRational<T>::operator/(const ECRational &rhs) const {
    ECRational<T> Recipirocal = ECRational<T>(rhs.denominator, rhs.numerator);
    return (*this * Recipirocal);
}

template <class T>
const T &ECRational<T>::GetNumerator() const {
    return this->numerator;
}

template <class T>
const T &ECRational<T>::GetDenominator() const {
    return this->denominator;
}
