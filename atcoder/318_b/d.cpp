
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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

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

	path(lint xx, lint yy, lint ccost): x(xx), y(yy), cost(ccost) {}
};

// 정수가 int형의 범위를 넘어가는지
// integer overflow 확인
// 정방향이 아닌 역방향도 생각해보기
void solve() {
	int n;		
	lint x;
	cin >> n;
	lint dp[1 << (n+1)][n+1];

	fill(&dp[0][0], &dp[(1<<(n+1))-1][n+1], 0);
	vector<path> graph;	

	for(int i = 1; i < n; i++) {
		for(int j = i + 1; j <= n; j++)	 {
			cin >> x;	
			graph.pb(path(i, j, x));
			dp[((1 << i) | (1 << j))][0] = x;
			// debug(i, j, (1 << i) | (1 << j), x);
		}
	}

	
	for(int z = 0; z < n; z++) {
	  for(int i = 0; i < (1 << n); i++)	 {
				if(dp[i][z] == 0) continue;
		  for(int j = 0; j < graph.size(); j++) {
			  int cx = graph[j].x;	
			  int cy = graph[j].y;	
			  lint ccost = graph[j].cost;	
			  if((i & ((1 << cx) | (1 << cy))) != 0) continue;
				dp[i | ((1 << cx) | (1 << cy))][z+1] = dp[i | ((1 << cx) | (1 << cy))][z+1] > dp[i][z] + ccost ? dp[i | ((1 << cx) | (1 << cy))][z+1] : dp[i][z] + ccost;
		  }
	  }
	}
	lint res = 0LL;
	for(int i = 0; i < (1 << (n + 1)); i++) {
		for(int j = 0; j <= n; j++){ 
			res = res > dp[i][j] ? res : dp[i][j];
		}
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
