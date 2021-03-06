/* 
 * File:   BigramMap.cpp
 * Author: amine
 * 
 * Created on December 19, 2016, 1:28 PM
 */
#include "BadData.h"
#include "BigramMap.h"
#include <fstream>
#include <sstream> 
#include<iostream>
#include <string>
#include <cstdlib>
#include<vector>
#include <exception>
#include <utility>
#include <limits>
#include <map>
#include <cstring>

using namespace std;

/******************************************************************************/
template <class T>
BigramMap<T>::BigramMap() : dataType(1) {
    setCountGrams(0);
}
/******************************************************************************/

/******************************************************************************/
template <class T>
BigramMap<T>::BigramMap(int _dataType) : dataType(_dataType) {
    setCountGrams(0);
}
/******************************************************************************/

/******************************************************************************/
template <class T>
void BigramMap<T>::setCountGrams(int _numGrams) {
    countGrams = _numGrams;
}
/******************************************************************************/

/******************************************************************************/
template <class T>
int BigramMap<T>::getCountGrams()const {
    return countGrams;
}
/******************************************************************************/

/******************************************************************************/
template <class T>
void BigramMap<T>::readFile(const char* filename) {

    ifstream inStream; //for input file
    string line;
    vector< pair<T, T> > allBigrams;
    //opened input file
    inStream.open(filename);

    //controlled if opening input file failed
    if (inStream.fail()) {
        cerr << "Opening input file o failed!" << endl;
        exit(1);
    }

    //get each line from file and calls line parser
    while (!inStream.eof()) {
        getline(inStream, line);
        lineParser(line);
    }

    if (!(isBadData()) && (elements.size() != 0)) {

        for (int i = 0, j = 1; j < elements.size(); ++i, ++j) {
            T _first = elements[i];
            T _second = elements[j];
            pair<T, T> p(_first, _second);
            allBigrams.push_back(p);

        }

        T _first = allBigrams[0].first;
        T _second = allBigrams[0].second;
        myMap.insert(make_pair(make_pair(_first, _second), 1));


        for (int index = 1; index < allBigrams.size(); ++index) {
            T _first = allBigrams[index].first;
            T _second = allBigrams[index].second;
            // auto iterator = myMap.find(make_pair(_first,_second));             
            if (myMap.count(make_pair(_first, _second)) > 0) {
                auto iterator = myMap.find(make_pair(_first, _second));
                ++(iterator->second);
            } else {
                myMap.insert(make_pair(make_pair(_first, _second), 1));
            }
        }

    }
    
    setCountGrams(myMap.size()); //calculated numGrams

    //closed input file
    inStream.close();
}
/******************************************************************************/

/******************************************************************************/
template <class T>
int BigramMap<T>::numGrams() const {
    return getCountGrams();
}
/******************************************************************************/

/******************************************************************************/
template <class T>
int BigramMap<T>::numOfGrams(T _first, T _second)const {
    if (getCountGrams() == 0)
        return 0;
    if (myMap.count(make_pair(_first, _second)) > 0) {
        auto iterator = myMap.find(make_pair(_first, _second));
        return iterator->second;
    } else {
        return 0;
    }
}
/******************************************************************************/

/******************************************************************************/
template <class T>
void BigramMap<T>::print(ostream& outp) const {

    if (getCountGrams() != 0) {
        auto iterator = myMap.begin();
        while (iterator != myMap.end()) {
            outp << iterator->first.first << "," << iterator->first.second << "  : ";
            outp << iterator->second << endl;
            ++iterator;
        }
    }
}
/******************************************************************************/

/******************************************************************************/
template <class U>
ostream& operator<<(ostream & outp, const Bigram<U>& bg) {
    bg.print(outp);
    return outp;
}
/******************************************************************************/

/******************************************************************************/
template<class T>
pair<T, T> BigramMap<T>::maxGrams() const {
    if (getCountGrams() != 0) {
        auto iterator = myMap.begin();
        auto pointerOfMax = myMap.begin();
        int max = iterator->second;
        ++iterator;
        for (; iterator != myMap.end(); ++iterator) {
            if (max < iterator->second) {
                max = iterator->second;
                pointerOfMax = iterator;
            }
        }
        T _first = pointerOfMax->first.first;
        T _second = pointerOfMax->first.second;
        pair<T, T> myPair(_first, _second);
        return myPair;
    }
    else{
    	pair<T,T> emptyPair;
    	return emptyPair;
    }
}
/******************************************************************************/

/******************************************************************************/
template <class T>
void BigramMap<T>::lineParser(string line) {
    stringstream sstream(line);
    stringstream sstreamOther(line);
    string strElem;
    T element;
    while (sstream >> element) {
        elements.push_back(element);
    }

    while (sstreamOther >> strElem) {
        strElements.push_back(strElem);
    }
}
/******************************************************************************/

/******************************************************************************/
template <class T>
void BigramMap<T>::output() {
    for (int i = 0; i < elements.size(); ++i)
        cout << elements[i] << " ";
    cout << endl;
}
/******************************************************************************/

/******************************************************************************/
template <class T>
bool BigramMap<T>::isBadData() throw (BadData) {

    bool isBadElement = false;

    if (elements.size() != strElements.size())
        isBadElement = true;
	//string
    if (dataType == 2) {

        for (int k = 0; k < strElements.size(); ++k) {
            string token = strElements[k];
            for (int i = 0; i < token.size(); ++i) {
                if (isdigit(token[i])) {
                    isBadElement = true;
                }
            }
        }

    }
    
    //double
    if (dataType == 3) {

        for (int k = 0; k < strElements.size(); ++k) {
            const char * token = strElements[k].c_str();
            if(strchr(token,'.')==nullptr)
                isBadElement = true;
        }

    }

    if (isBadElement) {
        BadData e;
        throw e;
        return true;
    } else
        return false;
}
/******************************************************************************/
