#include "DynamicIntArray.h"

DynamicIntArrayNumber::DynamicIntArrayNumber() {
    length = 8;
    array = new int[8];
}

DynamicIntArrayNumber::DynamicIntArrayNumber(int length) {
    this->length = length;
    array = new int[length];
    for (int i = 0; i < length; i++) {
        array[i] = 0;
    }
}

DynamicIntArrayNumber::DynamicIntArrayNumber(int length, int n) {
    this->length = length;
    array = new int[length];
    for (int i = 0; i < length; i++) {
        array[i] = n;
    }
}

DynamicIntArrayNumber::DynamicIntArrayNumber(const DynamicIntArrayNumber& dynamic) {
    int i;
    length = dynamic.length;
    array = new int[length];
    for (int i = 0; i < dynamic.length; i++) {
        array[i] = dynamic.array[i];
    }
}

DynamicIntArrayNumber::DynamicIntArrayNumber(DynamicIntArrayNumber&& dynamic)
    : array(dynamic.array), length(dynamic.length)
{
    dynamic.array = nullptr;

}

DynamicIntArrayNumber::~DynamicIntArrayNumber()
{
    delete[] array;
}

int& DynamicIntArrayNumber::operator[](const int index) {
    return array[index];
}

int DynamicIntArrayNumber::getSizeOfArray() {
    return length;
}

int DynamicIntArrayNumber::getElementOfArray(int i) {
    return array[i];
}

void DynamicIntArrayNumber::resize(int newLength) {
    int* newArray = new int[newLength];
    if (length >= newLength) {
        for (int i = 0; i < newLength; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        length = newLength;
        this->array = newArray;
    }
    if (length < newLength) {
        for (int i = 0; i < length; i++) {
            newArray[i] = array[i];
        }
        for (int k = 0; k < newLength - length; k++) {
            newArray[k + length] = 0;
        }
        delete[] array;
        length = newLength;
        this->array = newArray;
    }
}

DynamicIntArrayNumber& DynamicIntArrayNumber::operator=(const DynamicIntArrayNumber& dynamic) {
    delete[] array;
    length = dynamic.length;
    array = new int[length];
    for (int i = 0; i < length; i++) {
        array[i] = dynamic.array[i];
    }

    return *this;
}
DynamicIntArrayNumber& DynamicIntArrayNumber::operator=(DynamicIntArrayNumber&& dynamic) {
    delete[] array;
    length = dynamic.length;
    array = dynamic.array;
    dynamic.array = nullptr;
    return *this;
}

bool operator== (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2) {
    if (d1.length == d2.length) {
        for (int i = 0; i < d1.length; i++) {
            if (d1.array[i] != d2.array[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator != (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    return !(d1 == d2);
}

bool operator> (const const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    if (d1.length > d2.length) {
        return true;
    }
    if (d2.length > d1.length) {
        return false;
    }
    for (int i = 0; i < d1.length; i++) {
        if (d1.array[i] <= d2.array[i]) {
            return false;
        }
    }
    return true;
}

bool operator>= (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    if (d1.length > d2.length) {
        return true;
    }
    if (d2.length > d1.length) {
        return false;
    }
    for (int i = 0; i < d1.length; i++) {
        if (d1.array[i] < d2.array[i]) {
            return false;
        }
    }
    return true;
}

bool operator< (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    if (d1.length < d2.length) {
        return true;
    }
    if (d2.length < d1.length) {
        return false;
    }
    for (int i = 0; i < d1.length; i++) {
        if (d1.array[i] >= d2.array[i]) {
            return false;
        }
    }
    return true;
}

bool operator<= (const DynamicIntArrayNumber& d1, const DynamicIntArrayNumber& d2)
{
    if (d1.length < d2.length) {
        return true;
    }
    if (d2.length < d1.length) {
        return false;
    }
    for (int i = 0; i < d1.length; i++) {
        if (d1.array[i] > d2.array[i]) {
            return false;
        }
    }
    return true;
}

DynamicIntArrayNumber operator+(DynamicIntArrayNumber& d1, DynamicIntArrayNumber& d2) {

    DynamicIntArrayNumber result = DynamicIntArrayNumber(d1.length + d2.length);
    for (int i = 0; i < d1.length; i++) {
        result.array[i] = d1[i];
    }
    for (int i = d1.length; i < (d1.length + d2.length); i++) {
        result.array[i] = d2[i - d1.length];
    }
    return result;
}

ostream& operator<< (ostream& out, const DynamicIntArrayNumber& dynamic)
{
    out << "[";
    for (int i = 0; i < dynamic.length; i++) {
        out << dynamic.array[i] << ", ";
    }
    out << "]";

    return out;
}

istream& operator>> (istream& in, DynamicIntArrayNumber& dynamic)
{
    for (int i = 0; i < dynamic.length; i++) {
        in >> dynamic.array[i];
    }
    return in;
}

