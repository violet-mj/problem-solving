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
	int N, K, C, R;
	cin >> N >> K >> C >> R;
	vector<int> base(K);
	vector<int> si(K);
	vector<int> pi(K);
	vector<int> skill(K, 0);

	for(int i = 0; i < K; i++) cin >> base[i];
	for(int i = 0; i < K; i++) cin >> si[i];
	for(int i = 0; i < K; i++) cin >> pi[i];
	int stk = 0;
	int combo = 0;
	int tmp;
	lint stardust = 0;
	lint p = 0;
	bool flag = true;
	for(int i = 0; i < N; i++) {
		cin >> tmp;
		if(tmp == 0) {
			stk = max(0, stk - R);
			combo = 0;
		} else {
			tmp--;
			stardust += (lint)base[tmp] * (100 + combo * C)  * (100 + skill[tmp] * si[tmp]) / 10000LL;
			skill[tmp]++;
			combo++;
			stk += pi[tmp];
			if(stk > 100) {
				flag = false;
			}
		}
	}

	cout << (flag ? stardust : -1)<< "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
