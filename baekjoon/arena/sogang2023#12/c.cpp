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
	int n, q, x, y;	
	cin >> n;
	vector<int> house(n + 1);
	vector<int> check(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> house[i];
		check[house[i]] = i;
	}
	cin >> q;

	debug(check);
	for(int i = 0; i < q; i++) {
		cin >> x >> y;		
		vector<int> nw = check;		
		for(int i = x; i <= y; i++) {
			for(int j = i + 1; j <= y; j++)	 {
				if(nw[i] > nw[j])	{
					swap(nw[i], nw[j]);
				}
			}
		}
		debug(nw);
		vector<int> res(n + 1, 0);
		for(int i = 1; i <= n; i++) {
			res[nw[i]] = i;
		}

		for(int i = 1; i <= n; i++) {
			cout << res[i] << " \n"[i == n];
		}
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
