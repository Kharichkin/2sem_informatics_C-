#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }
    int N;
    N = a.size();

    int start;
    start = *max_element(a.begin(), a.end());

    int power = 10;
    int pow = 1;
    while (start / power != 0) {
        power = power * 10;
        pow = pow + 1;
    }

    int step = 1;
    for (int i = 0; i < pow; i++) {
        vector<int> b;

        for (int j = 0; j < N; j++) {
            if((a[j] / step + 3) % 2 != 0) {
                b.push_back(a[j]);
            }
        }

        for (int j = 0; j < N; j++) {
            if((a[j] / step + 1) % 2 == 0) {
                b.push_back(a[j]);
            }
        }

        for (int j = 0; j < (N - 1); j++) {
            a[j] = b[j];
            cout << a[j] << " ";
        }

        a[N - 1] = b[N - 1];
        cout << a[N - 1] << endl;
        step = step * 10;
    }

    return 0;
}
