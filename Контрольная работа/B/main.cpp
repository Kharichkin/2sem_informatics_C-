#include <iostream>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    int N = 0;

    for(int i = 0; i < text.size(); i++){
        if (text[i] == ' '){
            N++;
        }
    }

    cout << N + 1;

    return 0;
}
