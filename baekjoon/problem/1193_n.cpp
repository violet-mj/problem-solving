#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <format>

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
	int n, cnt, ccnt; cin >> n;

	for(int i = 1; i <= n; i++) {
		if((i * (i + 1) >> 1) >= n) {
			cnt = i - 1;
			ccnt = n - (i * (i - 1) >> 1);
			break;
		}
	}
	int hope = cnt + 2;
  int f = hope - ccnt;
  int s = ccnt;
  if(hope & 1) swap(f, s);
	cout << f << "/" << s;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++)
	solve();
}
