#pragma once
#include <iostream>

using namespace std;

class Rank {
private:
	int A[10] = { 56, 80, 98, 90, 67,88,80,70,99,100 };

public:
	Rank();
	void rank();
	void print();
};
