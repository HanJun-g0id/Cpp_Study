#include "SubTotal.h"
#include <iostream>
using namespace std;

int main() {
    vector<int> arr = { -1, 10, 5, 6, -2, 8, -18, 9, 15, -100 };

    int result = MaxSubTotal(arr);

    cout << "최대 부분합 : " << result;
    return 0;
}
