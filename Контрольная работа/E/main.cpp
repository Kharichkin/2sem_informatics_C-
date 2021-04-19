#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    double money = 0;
    for (int i = 1; i < N; i++){
        money = 0.7*(100 + 2*money);
    }

    cout << static_cast<int64_t>(0.3*(100 + 2*money) + 10);

    return 0;
}
