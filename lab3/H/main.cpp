#include <iostream>
using namespace std;

struct Cat {
    char *name;
    unsigned int id;
    double weight, length;
    unsigned int mice_caught;
};

Cat* get_home_for_a_cats_pride(unsigned int n) {
    Cat *cats = new Cat [n];
    return cats;
}
void clear_home_of_a_cats_pride(Cat *cats, unsigned int n){
    delete [] cats;
}

int main() {
    unsigned int n;
    cin >> n;
    Cat *a = get_home_for_a_cats_pride(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].weight >> a[i].length >> a[i].mice_caught;
        a[i].id = i;
    }
    for (int i = 0; i < n; i++)
        cout << a[i].name << " ";
    cout << endl;
    /*clear_home_of_a_cats_pride(a, n);*/
    return 0;
}
