
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

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

typedef long long ll;
ll n;

map<ll,ll> m;

ll recur(ll n) {

	if (n == 0) {
		return 1;
	}

	if(m.find(n) != m.end()) {
		return m[n];
	}

	m[n/2] = recur(n/2);
	m[n/3] = recur(n/3);

	return m[n/2] + m[n/3];
}

void solve() {
	cin >> n;

	ll result = recur(n);

	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
