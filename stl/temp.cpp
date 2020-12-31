#include <bits/stdc++.h>
#include "temp.h"

using namespace std;

template<class T>
temp<T>::temp(T& t): x(t) {};

template<class T>
void temp<T>::print() {
	cout << this->x << "\n";
}
