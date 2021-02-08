#include <iostream>

int main() {
    int a, N;
    N = 0;
    do{
        std::cin >> a;
        if (a % 2 == 0){
            N++;
        }
    } while (a != 0);
    std::cout << N-1 << std::endl;
    return 0;
}
