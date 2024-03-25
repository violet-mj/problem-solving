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

int mul(int a, int b, int m) {
	if(b == 0) return 1;
	int mid = mul(a, b / 2, m);
	if(b % 2 == 0) {
		return mid * mid % m;
	} else {
		return mid * mid % m * a % m;	
	}
}

void solve() {
	int n, m; cin >> n >> m;
	string cmd;
	vector<int> v(n + 1, 1);
	vector<int> pre(n + 1, 1);

	int total = 1;
	for(int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		v[i] = tmp % m;
	}

	int l = 1;
	int r = n;

	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] * v[i] % m;
	}
	debug(pre);
	cin >> cmd;

	for(int i = 0; i < cmd.size(); i++) {
		cout << pre[r] * mul(pre[l - 1], m - 2, m) << " ";
		if(cmd[i] == 'L')	 {
			l++;		
		} else {
			r--;	
		}
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
