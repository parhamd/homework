
#include<iostream>
using namespace std;

const int a = 28;
const int b = 32;
const int c = 37;
const int d = 24;
const int e = 33;

int int_sum(int nums[], int size) {
    int sum = 0;

    for(int i = 0; i < size; i++) {
        sum = sum +nums[i];
    }

    return sum;
}

int main() {
    int constants[6] = {a, b, c, d, e};
    int size = sizeof(constants) / sizeof(constants{0});

    int sum = int_sum(constants, size);
    double average = sum / 5;

    cout << average << '\n';

    return 0;
}
