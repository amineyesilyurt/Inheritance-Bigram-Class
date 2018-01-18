/* 
 * File:   BigramDyn.h
 * Author: amine
 *
 * Created on December 29, 2016, 11:33 AM
 */

#ifndef BIGRAMDYN_H
#define BIGRAMDYN_H


#include<iostream>
#include<map>
#include<vector>
#include <exception>
#include <utility> // make_pair
#include <exception>
#include "Bigram.h"
#include "BadData.h"

using namespace std;


template <class T>
class BigramDyn : public Bigram<T> {
public:
    BigramDyn();
    BigramDyn(int _dataType);
    virtual void readFile(const char* filename);
    virtual int numGrams()const;
    virtual int numOfGrams(T _first, T _second)const;   
    virtual void print(ostream& outp) const;
    virtual void output();
    //template<class U> friend ostream& operator<<(ostream & outp, const Bigram<U>& bg);
    virtual pair<T,T> maxGrams() const;
    int getCountGrams()const;
    void setCountGrams(int _numGrams);
private:
    map< pair<T, T>, int > myMap;
    vector<T> elements;
    vector<string> strElements;
    void lineParser(string line);
    bool isBadData() throw (BadData);
    int dataType;
    int countGrams;
};

#endif /* BIGRAMDYN_H */

