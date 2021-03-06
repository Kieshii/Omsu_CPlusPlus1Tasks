#include "DynamicIntArray.h"

int main() {
	DynamicIntArrayNumber Array1;
	cout << Array1 << endl;
	DynamicIntArrayNumber Array2(21);
	cout << Array2 << endl;
	DynamicIntArrayNumber Array3(21, 5);
	cout << Array3 << endl;
	DynamicIntArrayNumber Array4 = Array3;
	cout << Array4 << endl;

	Array4.resize(8);
	cout << Array4 << endl;
	cout << Array3 << endl;

	cout << Array4.getSizeOfArray() << endl;
	cout << Array4.getElementOfArray(3) << endl;

	if (Array2 == Array3) { cout << "Equal" << endl; }
	else cout << "Not Equal" << endl;

	if (Array2 != Array3) { cout << "Equal" << endl; }
	else cout << "Not Equal" << endl;

	DynamicIntArrayNumber Array5 = Array3;
	if (Array5 == Array3) { cout << "Equal" << endl; }
	else cout << "Not Equal" << endl;

	if (Array5 != Array3) { cout << "Equal" << endl; }
	else cout << "Not Equal" << endl;

	if (Array2 < Array3) { cout << "Lesser" << endl; }
	else cout << "Greater" << endl;

	if (Array3 > Array2) { cout << "Greater" << endl; }
	else cout << "Lesser" << endl;

	if (Array2 <= Array3) { cout << "Lesser" << endl; }
	else cout << "Greater" << endl;

	if (Array3 >= Array2) { cout << "Greater" << endl; }
	else cout << "Lesser" << endl;

	if (Array3 >= Array5) { cout << "Greater" << endl; }
	else cout << "Lesser" << endl;

	DynamicIntArrayNumber Array6 = Array2 + Array4;
	cout << Array6 << endl;
}