#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    vector<int> number;
    vector<int> numbers;

    bool new_number = true;
    for(int i = 0; i < text.size(); i++){
        if((int('0') <= int(text[i])) && (int(text[i]) <= int('9'))){
            if (new_number){
                int final = 0;
                for(int j = 0; j < number.size(); j++){
                    final += number[j] * pow(10, number.size()-j-1);
                }
                numbers.push_back(final);
                number.clear();

                new_number = false;
            }
            number.push_back(int(text[i]) - int('0'));
        }
        else{
            new_number = true;
        }
    }
    if(number.size() != 0){
        int final = 0;
        for(int j = 0; j < number.size(); j++){
            final += number[j] * pow(10, number.size()-j-1);
        }
        numbers.push_back(final);
        number.clear();
    }

    int max = 0;
    for (int i = 0; i < numbers.size(); i++){
        if(numbers[i] > max){
            max = numbers[i];
        }
    }

    cout << max;

    return 0;
}