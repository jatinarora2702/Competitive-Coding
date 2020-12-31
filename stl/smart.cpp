#include <bits/stdc++.h>
using namespace std;

class smart_ptr_int {
	int* x;
public:
	explicit smart_ptr_int(int*);
	~smart_ptr_int();
	int& operator*();
};

smart_ptr_int::smart_ptr_int(int* p = NULL): x(p) {};
smart_ptr_int::~smart_ptr_int() {
	delete this->x;
}
int& smart_ptr_int::operator*() {
	return *(this->x);
}

template<class T>
class smart_ptr {
	T* t;
public:
	explicit smart_ptr(T* = NULL);
	~smart_ptr();
	T& operator*();
	T* operator->();
};

template<class T>
smart_ptr<T>::smart_ptr(T* pt): t(pt) {};

template<class T>
smart_ptr<T>::~smart_ptr() {
	delete this->t;
}

template<class T>
T& smart_ptr<T>::operator*() {
	return *(this->t);
}

template<class T>
T* smart_ptr<T>::operator->() {
	return this->t;
}

int main() {
	smart_ptr_int ptr(new int());
	*ptr = 20;
	cout << *ptr << "\n";

	smart_ptr<int> ptr1(new int());
	*ptr1 = 100;
	cout << *ptr1 << "\n";


	unique_ptr<int> ptr2(new int(500));
	cout << *ptr2 << "\n";
	*ptr2 = 200;	
	cout << *ptr2 << "\n";

	return 0;
}