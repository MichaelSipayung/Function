// Function.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <initializer_list>
#include <varargs.h>
#include <vector>
void topLevelConst(const std::string&);
void nextTest(int*);
bool isSetence(const std::string&);
void print(const int*);
void print(const char*);
//using standart library convection to pass an array 
void print(const int*, const int*);
void print_All(const int a[],int );
//array parameter reference 
void print(int(&)[10]);
void varyingParam(std::initializer_list<std::string>);
void elipsParam(...);
void returnVal(double&, double&);
void minus_1(int(&)[12]);
void show_data(const int*,const int*);
void multiplyTwo(int(&)[12]);
const std::string& shorter(const std::string&, const std::string&);
char& get_val(std::string&, std::string::size_type);
//return vector 
std::vector<std::string> process();
long long recur(int);
//returns a pointer to an array of ten integer
auto func(int )->int(*)[5];