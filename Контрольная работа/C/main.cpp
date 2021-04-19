#include <iostream>

using namespace std;

int main() {
    string text, result;
    getline(cin, text);
    result = text;

    int N = 0;
    for(int i = 0; i < text.size(); i++){
        if (N % 2 == 0){
            result[i] = toupper(text[i]);
        }
        else{
            result[i] = tolower(text[i]);
        }
        if(text[i] != ' '){
            N++;
        }
    }

    cout << result;

    return 0;
}