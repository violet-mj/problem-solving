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

struct cmp {
	bool operator() (pii p1, pii p2) {
		return p1.s < p2.s;
	}
};

void solve() {
	int n, k;		
	cin >> n >> k;
	vector<pii> jew(n);
	vector<int> bag(k);
	priority_queue<pii, vector<pii>, cmp> pq;

	for(int i = 0; i < n; i++) {
		cin >> jew[i].f >> jew[i].s;	
	}

	for(int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(all(bag));
	sort(all(jew));
	debug(jew, bag);
	lint cnt = 0;
	int currp = 0;

	for(int i = 0; i < k; i++) {
		while(currp < n && jew[currp].f <= bag[i]) {
			pq.push(jew[currp++]);
		}
		if(pq.size() == 0) continue;
		pii currv = pq.top(); pq.pop();
		cnt = cnt +  (lint) currv.s;
	}

	cout << cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
