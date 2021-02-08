#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int speed, wage;
    string number;
    wage = 0;
    cin >> speed >> number;
    while (number != "A999AA") {
        if (speed > 60) {
            if ((number.substr(1, 1) == number.substr(2, 1)) && (number.substr(1, 1) == number.substr(3, 1))){
                wage += 1000;
            }
            else if ((number.substr(1, 1) == number.substr(2, 1)) || (number.substr(1, 1) == number.substr(3, 1)) || (number.substr(2, 1) == number.substr(3, 1))){
                wage += 500;
            }
            else{
                wage += 100;
            }
        }
        cin >> speed >> number;
    }
    cout << wage << endl;
    return 0;
}
