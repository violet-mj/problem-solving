#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>


using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second



void solve() {

	int k[10] = {0,};
	int tmp;

	for(int i = 0; i < 5; i++) {
		cin >> tmp;	
		k[tmp] += 1;
	}

	for(int i = 0; i < 10; i++) {
		if(k[i] % 2 == 1) {
			cout << i << "\n";
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
