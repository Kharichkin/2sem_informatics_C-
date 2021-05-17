#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Person{
    string name;
    long long phone;
    int money;
};

bool compare (Person a, Person b){
    if (a.money != b.money){
        return a.money > b.money;
    }
    else{
        if (a.name != b.name) return a.name < b.name;
        else return a.phone < b.phone;
    }
}

int main() {
    int N;

    cin >> N;
    vector <Person> people(N);

    for (int i = 0; i < N; i++){
        cin >> people[i].name;
        cin >> people[i].phone;
        cin >> people[i].money;
    }

    sort(people.begin(), people.end(), compare);

    for (int i = 0; i < min(N, 10); i++){
        cout << people[i].name << ' ' << people[i].phone << ' ' << people[i].money << endl;
    }

    return 0;
}
