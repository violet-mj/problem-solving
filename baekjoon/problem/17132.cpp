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

const lint INF = 1LL << 60;

struct UF {
	vector<int> parent;	
	vector<int> nodeSize;
	vector<lint> nodeWeight;
	int size;
	lint res;
	
	UF(int size): size(size), res(0){
		parent.resize(size + 1);
		nodeSize.resize(size + 1, 1);
		nodeWeight.resize(size + 1, INF);
		for(int i = 1; i <= size; i++) {
			parent[i] = i;	
		}
	}

	lint printAnswer() {
		return res;	
	}

	int findRoot(lint v) {
			if(v != parent[v]) {
				parent[v] = findRoot(parent[v]);
			}
			return parent[v];
	}

	int findSize(int v) {
		return nodeSize[findRoot(v)];
	}

	void unionNode(lint a, lint b, lint cost) {
		a = findRoot(a);
		b = findRoot(b);
		if(a > b) {
			parent[a] = b;	
			res += ((lint)nodeSize[b]  * nodeSize[a]) * cost;
			nodeSize[b]+=nodeSize[a];
		} else {
			parent[b] = a;	
			nodeWeight[a] = min(nodeWeight[a], (lint)cost);
			res += ((lint)nodeSize[a] * nodeSize[b]) * cost; 
			nodeSize[a]+=nodeSize[b];
		}
	}

};

void solve() {
	lint n, a, b, c;	
	cin >> n;
	UF* dsu = new UF(n - 1);
	vector<vector<lint>> edge;
	for(int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		edge.pb({a, b, c});
	}
	sort(all(edge), [](vector<lint>& v1, vector<lint>& v2) {
		return v1[2] > v2[2];
	});

	for(int i = 0; i < n - 1; i++) {
		vector<lint> tmp = edge[i];
		dsu->unionNode(tmp[0], tmp[1], tmp[2]);
	}

	cout << dsu->printAnswer() << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
