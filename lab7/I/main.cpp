#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a;
    vector<int> b;

    int x;

    while (cin >> x){
        a.push_back(x);
    }

    int N = a.size();

    for (int i = 0; i < N; i++){
        if (a[i] % 2 == 0){
            b.push_back(a[i]);
        }
    }

    sort(b.begin(), b.end());
    int n = b.size();

    for (int i = 0; i < N; i++){
        if (a[i] % 2 != 0){
            b.push_back(a[i]);
        }
    }

    sort(b.begin() + n, b.end());

    for (int i = 0; i < N; i++){
        cout << b[i] << ' ';
    }
    return 0;
}
