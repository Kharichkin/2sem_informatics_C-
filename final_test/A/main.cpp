#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    bool flag = false;

    cin >> N;
    vector<int> array1(N);
    vector<int> array2(N);

    for (int i = 0; i < N; i++){
        cin >> array1[i];
        cin >> array2[i];
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                if ((i != j) && (i != k) && (j != k)){
                    if ((array1[i] + array1[j] == array1[k]) && (array2[i] + array2[j] == array2[k])){
                        flag = true;
                    }
                }
            }
        }
    }

    if (flag){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}
