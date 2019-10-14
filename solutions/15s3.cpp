#include <bits/stdc++.h>

using namespace std;


int main() {
    int g;
    int p;
    cin >> g;
    cin >> p;
    set<int> gates;

    //gates.insert(0);

    for (int i = 0; i < g + 1; i++) {
      gates.insert(-i);
    }

    for (int i = 0; i < p; i++) {
        int maxgate;
        cin >> maxgate;

        set<int>::iterator unocc = gates.lower_bound(-maxgate);

        if (*unocc == 0) {
            cout << i << endl;
            return 0;
        }
        gates.erase(unocc);

    }

    cout << p << endl;
    return 0;
}
