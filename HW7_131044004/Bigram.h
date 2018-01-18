/* 
 * File:   Bigram.h
 * Author: Amine
 * 
 * Created on December 19, 2016, 11:43 
 */

#ifndef BIGRAM_H
#define BIGRAM_H
#include<iostream>
#include<map>
#include<vector>
#include <exception>
#include <utility> // make_pair
using namespace std;
template <class T>
class Bigram {
public:
    virtual void readFile(const char* filename)=0;
    virtual int numGrams()const=0;
    virtual int numOfGrams(T _first, T _second)const=0;
    virtual void print(ostream& outp) const=0;//for operator <<
    virtual pair<T,T> maxGrams() const=0;
    virtual void output()=0;
};

#endif /* BIGRAM_H */

