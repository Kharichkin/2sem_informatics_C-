#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    int slippers [N];

    for (int i = 0; i < N; i++){
        cin >> slippers[i];
    }

    int distance = N;

    for (int i = 0; i < N; i++){
        if (slippers[i] < 0){
            for (int j = i + 1; j < N; j++){
                if ((slippers[j] == -slippers[i]) && (j - i < distance)){
                    distance = j - i;
                }
            }
        }
    }

    if(distance == N){
        cout << 0;
    }
    else{
        cout << distance;
    }

    return 0;
}
