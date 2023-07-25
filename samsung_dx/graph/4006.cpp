#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

int t, n, m, s, e, c;
int parent[50001];

struct einfo {
	int start;
	int end;
	int cost;
};

bool operator < (einfo a, einfo b) {
	return a.cost < b.cost;
}

int findNode(int x) {
	if(x != parent[x]) {
		parent[x] = findNode(parent[x]);
	}
	return parent[x];
}

void unionNode(int x, int y) {
	x = findNode(x);
	y = findNode(y);

	if(x < y) {
		parent[y] = x;	
	} else {
		parent[x] = y;	
	}
	
}

void solve(int tn) {
	if(debug) cout << "1" << "\n";
	cin >> n >> m;

	vector<einfo> v;

	if(debug) cout << "1" << "\n";
	fill(&parent[0], &parent[50001], 0);
	for(int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	if(debug) cout << "2" << "\n";
	for(int i = 0; i < m; i++) {
		cin >> s >> e >> c;	
		einfo currEdge;
		currEdge.start = s;
		currEdge.end = e;
		currEdge.cost = c;
		v.pb(currEdge);
	}
	sort(v.begin(), v.end());

	if(debug) cout << "3" << "\n";
	int result = 0;

	for(einfo curr: v) {
		if(findNode(curr.start) != findNode(curr.end)) {
			unionNode(curr.start, curr.end);
			result += curr.cost;
		}

		if(debug) {
			cout << "parent\n";	
			for(int i = 1; i <= n; i++ ) cout << parent[i] << " ";
			cout << "\n";
		}
	}

	if(debug) cout << "4" << "\n";

	cout << "#" << tn << " " << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}
