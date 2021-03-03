#include <iostream>

int main() {
    int *a = new int[3];
    a[0] = 1; a[1] = 2; a[2] = 3;
    int *ptr = a;
    delete [] a;
    std::cout << *a << std::endl;
    return 0;
}
