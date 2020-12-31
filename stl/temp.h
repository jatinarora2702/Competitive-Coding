#ifndef TEMP_H
#define TEMP_H

template<class T>
class temp {
	T x;
public:
	temp(T&);
	void print();
};

#include "temp.cpp"	// need this here, for templates.. since, the compiler needs to know the implementations!

#endif