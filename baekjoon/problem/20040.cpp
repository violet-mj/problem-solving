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

struct UF {
	int parent[500001];

	UF() {
		for(int i = 1; i <= 500000; i++) {
			parent[i] = i;	
		}
	}

	int find(int a) {
		if(a != parent[a])	 {
			return parent[a] = find(parent[a]);
		}
		return parent[a];
	}

	void unionNode(int a, int b) {
		a = find(a);	
		b = find(b);

		if(a >= b) {
			parent[a] = b;	
		} else {
			parent[b] = a;	
		}
	}
};

void solve() {
	int n, m;	cin >> n >> m;
	UF uf;

	for(int i = 0; i < m; i++) {
		int f, s; cin >> f >> s;	

		if(uf.find(f) != uf.find(s)) {
			uf.unionNode(f, s);
			continue;
		}

		cout << i + 1 << "\n";
		return;
	}

	cout << 0 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
