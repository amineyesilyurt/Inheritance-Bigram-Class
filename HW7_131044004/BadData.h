/* 
 * File:   BadData.h
 * Author: amine
 *
 * Created on December 27, 2016, 10:25 AM
 */

#ifndef BADDATA_H
#define BADDATA_H
#include <exception>
#include<iostream>
#include<cstdlib>
#include<string>
#include <exception>
using namespace std;

class BadData: public exception
{
  virtual const char* what() const throw()
  {
    return "Detected bad data!!";
  }
};

#endif /* BADDATA_H */

