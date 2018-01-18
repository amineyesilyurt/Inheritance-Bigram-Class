/* 
 * File:   BigramMap.h
 * Author: amine
 *
 * Created on December 19, 2016, 1:28 PM
 */

#ifndef BIGRAMMAP_H
#define BIGRAMMAP_H
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
class BigramMap : public Bigram<T> {
public:
    BigramMap();
    BigramMap(int _dataType);
    virtual void readFile(const char* filename);
    virtual int numGrams()const;
    virtual int numOfGrams(T _first, T _second)const;   
    virtual void print(ostream& outp) const;
    virtual void output();
    template<class U> friend ostream& operator<<(ostream & outp, const Bigram<U>& bg);
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

#endif /* BIGRAMMAP_H */

