#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

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
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()


void solve() {
	lint n, m;		
	cin >> n >> m;
	vector<lint> values(n);
	priority_queue<lint> pq;
	lint init = 0LL;
	for(int i = 0; i < n; i++) {
		cin >> values[i];
		pq.push(values[i]);
		init += values[i];
	}
		
	m = m % init;
	lint minA = *min_element(all(values));

	int idx = 0;

	auto check = [&]() {
		lint res = 0;
		for(int i = 0; i < n; i++) {
			if(values[i] <= m) {
				res += values[i];
				m -= values[i];
			}
		}
		return res;
	};

	while(1) {
		lint a = check();
		if(a == 0) break;
		m = m % a;
	}

	cout << m << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
