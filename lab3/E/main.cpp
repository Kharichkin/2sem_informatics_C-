#include <iostream>
using namespace std;

int do_some_awesome_work(int* a, int* b){
    return *a + *b;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << do_some_awesome_work(&a, &b) << endl;
    return 0;
}
