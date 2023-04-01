//
//  ECPolynomial.cpp
//  
//
//  Created by Yufeng Wu on 9/17/22.
//

#include "ECPolynomial.h"
#include <iostream>
#include <vector>
using namespace std;

ECPolynomial::ECPolynomial() {}

ECPolynomial::ECPolynomial(const std::vector<double> &listCoeffsIn) : listCoefs(listCoeffsIn) {
    this->fixZeros();
}



ECPolynomial::ECPolynomial(const ECPolynomial &rhs) {
    this->listCoefs = rhs.listCoefs;
    this->fixZeros();
}

int ECPolynomial::GetDegree() const {
    if (this->listCoefs.size() == 0) { return 0; }
    return this->listCoefs.size() - 1;
}

ECPolynomial ECPolynomial::Scale(double factor) const {
    if (factor == 0) {
        return ECPolynomial();
    }
    vector<double> vec;
    for (double i : this->listCoefs) {
        vec.push_back(i * factor);
    }
    return ECPolynomial(vec);
}

ECPolynomial ECPolynomial::operator+(const ECPolynomial &rhs) const {
    ECPolynomial res;
    auto leftIterator = listCoefs.begin();
    auto rightIterator = rhs.listCoefs.begin();
    while (leftIterator != listCoefs.end() && rightIterator != rhs.listCoefs.end())
    {
        res.listCoefs.push_back(*leftIterator + *rightIterator);
        rightIterator++;
        leftIterator++;
    }
    
    while (rightIterator != rhs.listCoefs.end())
    {
        res.listCoefs.push_back(*rightIterator);
        rightIterator++;
    }

    while (leftIterator != listCoefs.end())
    {
        res.listCoefs.push_back(*leftIterator);
        leftIterator++;
    }


    res.fixZeros();
    return res;
}

ECPolynomial ECPolynomial::operator*(const ECPolynomial &rhs) const {
    std::vector<double> result(this->listCoefs.size() + rhs.listCoefs.size() - 1, 0);
    for (int i = 0; i < this->listCoefs.size(); i++) {
        for (int j = 0; j < rhs.listCoefs.size(); j++) {
            result[i+j] += this->listCoefs[i] * rhs.listCoefs[j];
        }
    }
    ECPolynomial polyResult(result);
    polyResult.fixZeros();
    return polyResult;
}

void ECPolynomial::fixZeros() {
    if(this->listCoefs[listCoefs.size() - 1] == 0 || (this->listCoefs[listCoefs.size() - 1] < 0.0000000001)){
        int i = this->listCoefs.size() - 1;
        while(i >= 0 && this->listCoefs[i] < 0.0000000001){
            this->listCoefs.pop_back();
            i--;
        }
    }
}

ECPolynomial ECPolynomial::divideHelp(const ECPolynomial &rhs, ECPolynomial &rem) const {
    vector<double> quotient;
    for (int i = 0; i < (GetDegree() + rhs.GetDegree() + 1); i++) {
        quotient.push_back(0);
    }
    ECPolynomial dividend(listCoefs);

    for (int i = GetDegree(); i >= 0 && i >= rhs.GetDegree(); i--)
    {
        double coeff = dividend.listCoefs[i] / rhs.listCoefs[rhs.GetDegree()];
        quotient[i - rhs.GetDegree()] = coeff;
        for (int j = 0; j <= rhs.GetDegree(); j++)
        {
            dividend.listCoefs[i - rhs.GetDegree() + j] -= coeff * rhs.listCoefs[j];
        }
    }

    rem = dividend;
    ECPolynomial result(quotient);
    result.fixZeros();
    rem.fixZeros();
    return result;
}

ECPolynomial ECPolynomial::operator/(const ECPolynomial &rhs) const {
    ECPolynomial Remainder, Result;
    Result = this->divideHelp(rhs, Remainder);
    Result.fixZeros();
    return Result;
}

ECPolynomial ECPolynomial::operator%(const ECPolynomial &rhs) const {
    ECPolynomial Remainder, Result;
    Result = this->divideHelp(rhs, Remainder);
    Result.fixZeros();
    return Remainder;
}
void ECPolynomial::Dump() const {
    cout << "Deg: " << GetDegree() << ":  ";
    ECPolynomial copy(listCoefs);
    for(double d : copy.listCoefs){
        cout << d << ' ';
    }
    cout << endl;
}