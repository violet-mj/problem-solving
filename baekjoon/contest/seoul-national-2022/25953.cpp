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
typedef tuple<int, int, int> tlll;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

const int INF = 1LL << 30;
int n, times, edges;
int startPoint, endPoint;
struct node {
	int currNode;
	int time;
	int cost;

	node(int cNode, int ttime, int ccost): currNode(cNode), time(ttime), cost(ccost) {}
};

struct comp {
	bool operator () (tlll t1, tlll t2) {
		return get<0>(t1) >= get<0>(t2);
	}
};

void solve() {
	cin >> n >> times >> edges >> startPoint >> endPoint;
	vector<vector<node>> graph(n+1);
	vector<vector<int>> distance(times+1, vector<int>(n+1, INF));
	int ss, ee, cc;	
	for(int i = 1; i <= times; i++) {
		for(int j = 0; j < edges; j++)	 {
			cin >> ss >> ee >> cc;	
			graph[ss].pb(node(ee, i, cc));
			graph[ee].pb(node(ss, i, cc));
		}
	}

	priority_queue<tlll, vector<tlll>, comp> pq;
	pq.push(mt(0, 0, startPoint));
	distance[0][0] = 0;

	while(!pq.empty()) {
		auto [currC, currT, currN] = pq.top();
		pq.pop();

		if(currN == endPoint) {
			cout << currC << "\n";
			return;
		}

		if(currC > distance[currT][currN]) {
			continue;	
		}

		for(auto [nextN, nextT, nextC]: graph[currN]) {
			if(nextT <= currT) continue;
			if(currC + nextC < distance[nextT][nextN]) {
				distance[nextT][nextN] = currC + nextC;	
				pq.push(mt(distance[nextT][nextN], nextT, nextN));
			}
		}
	}
	int res = INF;
	for(int i = 0; i <= times; i++) {
		res = min(distance[times][endPoint], res);
	}

	cout << (res == INF ? -1 : res) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
