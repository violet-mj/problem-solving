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
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

const int INF = 1e9 + 1;

void solve() {
	int n;
	cin >> n;
	int max_ = -INF;
	int min_ = INF;
	for(int i = 0; i < n; i++) {
		int a, b;		
		cin >> a >> b;
		max_ = max(max_, b);
		min_ = min(min_, b);
	}

	cout << max_ - min_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
