#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}