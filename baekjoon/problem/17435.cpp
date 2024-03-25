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
	// functional graph

	int n, q, x, y;			
	cin >> n;
	vector<int> v(n+1, 0);
	vector<vector<int>> sparse(20, vector<int>(n + 1, 0));
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		sparse[0][i] = v[i];
	}
	for(int i = 1; i < 20; i++) {
		for(int j = 1; j <= n; j++) {
			int tmp = sparse[i-1][j];
			sparse[i][j] = sparse[i-1][tmp];
		}
	}

	cin >> q;

	for(int i = 0; i < q; i++) {
		cin >> x >> y;	
		int cur = y;
	  for(int i = 20; i >= 0; i--) {
		  if(x & (1 << i))	{
				cur = sparse[i][cur];
			}
	  }
		cout << cur << "\n";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
