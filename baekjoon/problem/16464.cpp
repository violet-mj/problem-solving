#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;

void solve() {

    cin >> n;

    int sqrtN = (int)sqrt(n);
    int i = 2;
    while(1) {
        if(i * (i - 1) / 2 > n) break;
        int ss = n - i * (i-1) / 2;
        int s = ss / i;

        if(s * i == ss) {
            cout << "Gazua" << "\n";
            return;
        } 
        i++;
    }

    cout << "GoHanGang" << "\n";
    return;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }
}
