#include <iostream>
using namespace std;

int main() {
    int a, max, Nmax;
    max = 0;
    Nmax = 0;
    do{
        cin >> a;
        if (a > max){
            max = a;
            Nmax = 1;
        }
        else if (a == max){
            Nmax++;
        }
    } while (a != 0);
    cout << Nmax << endl;
    return 0;
}
