
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
	int n; cin >> n;			
	vector<pii> p(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> p[i].f >> p[i].s;	
	}

	for(int i = 1; i <= n; i++) {
		int currDist = -1;
		int farNode = -1;
		for(int j = 1; j <= n; j++)	{
			int diffx = abs(p[i].f - p[j].f);
			int diffy = abs(p[i].s - p[j].s);
			int dist = diffx * diffx + diffy * diffy;
			if(dist > currDist) {
				currDist = dist;
				farNode = j;
			}
		}
		debug(farNode, currDist);
		cout << farNode << "\n";
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
