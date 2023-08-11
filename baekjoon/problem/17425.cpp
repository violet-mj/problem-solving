
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
	int n;	

	cin >> n;

	long long cnt = 0;
	long long j = 0;

	for(long long i = 1; i <= n; i = j + 1) {
		j = n / (n / i);
		cnt += (n/i) * (j * (j + 1) / 2 - i * (i - 1) / 2);
	}

	cout << cnt << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
}
