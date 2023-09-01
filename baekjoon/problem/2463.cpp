#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

#ifndef ONLINE_JUDGE
#include "/Users/mj/.vim/template/debug.cpp"
#else
#define debug(x...)
#endif
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long lint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;


template<int SIZE = 100000>
class dsu {
	private:
		int parent[SIZE + 1];
		int rank[SIZE + 1];
	public:
		void unionNode(int a, int b) {
			a = findRoot(a);
			b = findRoot(b);
			
			if(rank[a] < rank[b]) {
				swap(a, b);
			}

			parent[b] = a;
			rank[a] += rank[b];
		}
		dsu() {
			fill(rank, rank + SIZE + 1, 1);
			for(int i = 0; i <= SIZE; i++) parent[i] = i;
		}



		int findRoot(int x) {
			if(parent[x] != x) {
				return parent[x] = findRoot(parent[x]);
			}
			
			return parent[x];
		}

		lint getSize(int x) {
			return (lint)rank[x];
		}
		
};



struct path {
	int x;
	int y;
	lint cost;
	
	path(int xx, int yy, int ccost): x(xx), y(yy), cost(ccost) {}
};

const lint MOD = 1000000000;
int n, m, v1, v2;
lint c;

void solve() {
	cin >> n >> m;
	vector<path> graph;
	dsu<100000> DSU;
	lint sum_ = 0;
	for(int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> c;
		graph.pb(path(v1, v2, c));
		sum_ += c;
	}

	sort(graph.begin(), graph.end(), [](path p1, path p2) {
		return p1.cost > p2.cost;
	});

	lint curr = 0;
	lint res = 0;

	for(auto p: graph) {
		int left = p.x;
		int right = p.y;
		lint weight = p.cost;
		
		
		if(DSU.findRoot(left) != DSU.findRoot(right)) {
			lint lSize = DSU.getSize(DSU.findRoot(left));
			lint rSize = DSU.getSize(DSU.findRoot(right));
			lint addRes = lSize + rSize;
			lint a1 = addRes * (addRes - 1) / 2;
			lint a2 = lSize * (lSize - 1) / 2;
			lint a3 = rSize * (rSize - 1) / 2;

			res = (res + ((a1 - a2 - a3) % MOD) * ((sum_ - curr) % MOD)) % MOD;
			DSU.unionNode(left, right);
		}
		curr += weight;
		// cout << " left : " << left << " right : " << right << " " <<  res << "\n";
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
