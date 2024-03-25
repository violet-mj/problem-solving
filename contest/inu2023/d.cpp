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
	int n, k, t;		
	cin >> n >> k >> t;
	vector<int> shark(n);
	priority_queue<int> pq;
	for(int i = 0; i < n; i++) cin >> shark[i];
	sort(all(shark));

	int point = 0;
	lint sharkInit = (lint)t;
	int i = 0;
	int kcnt = 0;
	while(kcnt < k) {
		while(shark[i] < sharkInit && i < n) {
			pq.push(shark[i]);
			i++;
		}
		if(pq.size() == 0) break;
		int maxShark = pq.top();
		pq.pop();
		sharkInit += (lint)maxShark;
		kcnt++;
	}

	cout << sharkInit << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
