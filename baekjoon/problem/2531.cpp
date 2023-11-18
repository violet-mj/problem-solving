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
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	map<int, int> kinds;
	vector<int> sushi(n);
	for(int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	debug(sushi);
	int cnt = 0;
	int res = 0;
	for(int i = 0; i < k; i++) {
		if(kinds[sushi[i]] == 0) {
			cnt++;	
		}
		kinds[sushi[i]]++;
		debug(kinds, cnt);
	}
	if(kinds[c] == 0) {
		cnt++;
	}
	res = max(cnt, res);
	
	debug(res);

	for(int i = k; i != k - 1; i = (i + 1) % n){

		debug(1, res, sushi[i], (i - k + n) % n, i, kinds);
		if(kinds[sushi[i]] == 0) {
			cnt++;	
			if(sushi[i] == c) cnt--;
		}
		kinds[sushi[i]]++;

		debug(2, res, sushi[i], (i - k + n) % n, i, kinds);
		if(sushi[(i - k + n) % n] == c && kinds[sushi[(i - k + n) % n]] == 1) cnt++;
		if(kinds[sushi[(i - k + n) % n]] == 1) cnt--;	
		kinds[sushi[(i - k + n) % n]]--;
		res = max(cnt, res);
		debug(3, res, sushi[i], (i - k + n) % n, i, kinds);
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
