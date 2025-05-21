#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVec(vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}