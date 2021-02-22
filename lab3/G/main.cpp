#include <iostream>
using namespace std;

struct Cat{
    char name[20];
    unsigned int id;
    double weight, length;
    unsigned int mice_caught;
};

unsigned int count_total_mice_amount(Cat* cats, unsigned int n){
    unsigned int sum = 0;
    for (int i = 0; i < n; i++){
        sum += cats[i].mice_caught;
    }
    return sum;
}

int main() {
    unsigned int n;
    cin >> n;
    Cat *array = new Cat[n];
    for (int i = 0; i < n; i++){
        cin >> array[i].name >> array[i].weight >> array[i].length >> array[i].mice_caught;
        array[i].id = i;
    }

    cout << count_total_mice_amount(array, n) << endl;
    delete [] array;

    return 0;
}