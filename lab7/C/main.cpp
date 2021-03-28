#include <iostream>
#include <iomanip>
using namespace std;

void output(double N){
    if ((double)((int) N) == N){
        cout << N << ".0";
    } else if (((double)((int) (N * 10)) == N * 10)){
        cout << fixed << setprecision(1) << N;
    } else if (((double)((int) (N * 100)) == N * 100)){
        cout << fixed << setprecision(2) << N;
    } else {
        cout << fixed << setprecision(3) << N;
    }
}

int main() {
    int a, sum, N;
    double sum_of_squares;
    N = 0;
    sum = 0;
    sum_of_squares = 0;

    cin >> a;

    while (a != 0){
        N++;
        sum += a;
        sum_of_squares += a*a;

        cin >> a;
    }

    output(double(sum)/double(N));
    cout << " ";
    output(double(sum_of_squares)/double(N) - (double(sum)/double(N))*(double(sum)/double(N)));

    return 0;
}