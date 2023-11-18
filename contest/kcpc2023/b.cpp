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

const lint INF = (1 << 30) + 1;

void solve() {
	lint n, d, cmd, tmp;		
	cin >> n >> d;
	vector<int> v1;
	vector<int> v2;

	for(int i = 0; i < n; i++) {
		cin >> cmd >> tmp;	
		if(cmd == 1) {
			v1.pb(tmp);
		} else {
			v2.pb(tmp);
		}
	}

	int i, j, z;
	sort(all(v1));
	sort(all(v2));
	for(i = 0, j = 0, z = 0; i < n; i++) {
		debug(d, v1, v2);
		if(j >= v1.size()) break;
		if(d > v1[j])	{
			d += v1[j];
			d = min(d, INF);
			j++;
		} else {
			if(z >= v2.size()) continue;
			d *= v2[z];
			d = min(d, INF);
			z++;
		}
	}
	cout << v2.size() + j << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
