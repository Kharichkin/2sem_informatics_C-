#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    string s;

    cin >> s;

    vector<vector<long long>> array(s.size(), vector<long long>(4, 0));

    array[0][0] = s[0] == "uddu"[0];
    for (int i = 1; i < s.size(); i++) {
        array[i][0] = array[i - 1][0] + int(s[i] == "uddu"[0]);
    }

    for (int j = 1; j < 4; j++) {
        for (int i = j; i < s.size(); i++) {
            array[i][j] = array[i - 1][j] + (s[i] == "uddu"[j] ? array[i - 1][j - 1] : 0);
        }
    }

    cout << array.back().back();
}
