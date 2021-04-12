#include <iostream>

using namespace std;

float find_root(float f(float), float a, float b, float tol){
    float left, right;
    if (f(a) < 0){
        left = a;
        right = b;
    }
    else{
        left = b;
        right = a;
    }
    float result = (left + right)/2;

    while (abs(f(result)) > tol){
        if(f(result) > 0){
            right = result;
        }
        else{
            left = result;
        }
        result = (left + right)/2;
    }

    return result;
}

int main() {
    float root = find_root(x*x, )

    return 0;
}
