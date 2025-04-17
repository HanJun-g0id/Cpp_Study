#include <iostream>
using namespace std;

class Sum_Matrix {
private:
	int N, M, total;
	int A[3][4] = {
		{5,7,4,3},
		{6,1,8,3},
		{3,2,7,6}
	};
public:
	Sum_Matrix();
	void Sum_col(int b);
	void Sum_row(int a);
};
