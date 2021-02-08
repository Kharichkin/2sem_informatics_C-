#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}