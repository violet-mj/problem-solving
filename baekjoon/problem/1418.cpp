#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/Users/mj/.vim/template/debug.cpp"
#else
#define debug(x...)
#endif


typedef long long lint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

int n, k;

int sqrt(lint k) {
	lint l = 0;
	lint r = 1000000009;

	while(l + 1 < r) {
		lint mid = (l + r) >> 1;

		if(mid * mid < k) {
			l = mid;	
		} else {
			r = mid;	
		}
	}

	return (int) l;
}

vector<int> erathos(int toNum) {
	int sqrtN = sqrt((lint) toNum);
	vector<bool> check(toNum + 1, true);
	for(int i = 2; i <= sqrtN; i++) {
		if(check[i]) {
			for(int j = 2 * i; j <= toNum; j += i)	 {
				check[j] = false;	
			}
		}
	}

	vector<int> prime;

	for(int i = 2; i <= toNum; i++) {
		if(check[i]) {
			prime.pb(i);
		}
	}

	return prime;
}

void solve() {
	cin >> n >> k;

	vector<int> prime = erathos(100000);

	vector<bool> check(n + 1, true);

	for(auto p: prime) {
		if(p <= k) continue;
		for(int i = p; i <= n; i += p) {
			check[i] = false;	
		}
	}

	int cnt = 0;

	for(int i = 1; i <= n; i++) {
		if(check[i]) cnt++;
	}

	cout << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
