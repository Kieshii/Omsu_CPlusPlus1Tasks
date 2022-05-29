#pragma once
#include <iostream>
using namespace std;

class DynamicIntArrayNumber {
private:
    int* array;
    int length;

public:
    DynamicIntArrayNumber();
    DynamicIntArrayNumber(int length);
    DynamicIntArrayNumber(int length, int n);
    DynamicIntArrayNumber(const DynamicIntArrayNumber& dynamic);
    DynamicIntArrayNumber(DynamicIntArrayNumber&& dynamic);
    ~DynamicIntArrayNumber();

    int getSizeOfArray();
    int getElementOfArray(int i);
    void resize(int newLength);

    int& operator[](const int index);

    DynamicIntArrayNumber& operator=(const  DynamicIntArrayNumber& diname);
    DynamicIntArrayNumber& operator=(DynamicIntArrayNumber&& dynamic);

    friend bool operator == (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2);
    friend bool operator != (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2);

    friend bool operator> (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2);
    friend bool operator<= (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2);

    friend bool operator< (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2);
    friend bool operator>= (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2);

    friend DynamicIntArrayNumber operator+(DynamicIntArrayNumber& d1, DynamicIntArrayNumber& d2);

    friend ostream& operator<<(ostream& out, const DynamicIntArrayNumber& d1);
    friend istream& operator>>(istream& in, DynamicIntArrayNumber& d1);
};