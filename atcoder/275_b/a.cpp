
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

int n, tmp;
vector<int> v;

void solve() {
	cin >> n;	

	int max_ = -1;
	int maxIndex = -1;

	for(int i = 1; i <= n; i++) {
		cin >> tmp;	
		if(tmp > max_) {
			max_ = tmp;
			maxIndex = i;
		}
	}

	cout << maxIndex << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
