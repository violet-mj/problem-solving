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
	int parent[100001];
	UF() {
		for(int i = 0; i < 100001; i++) parent[i] = i;
	}	

	int find(int a) {
		if(parent[a] != a) return parent[a] = find(parent[a]);
		return parent[a];
	}

	void unionNode(int& a, int& b) {
		int aa = find(a);	
		int bb = find(b);
		if(aa < bb) parent[bb] = aa;
		else parent[aa] = bb;
	}
};

void solve() {
	int n;		
	cin >> n;
	vector<vector<int>> k(n, vector<int>(3));

	for(int i = 0; i < n; i++) {
		cin >> k[i][0] >> k[i][1] >> k[i][2];
	}

	vector<vector<int>> ks;

	for(int i = 0; i < 3;i ++) {
	  sort(all(k), [&](vector<int>& v1, vector<int>& v2) {
			return v1[i] < v2[i];
	  });
		for(int j = 0; j < n - 1; j++) {
			ks.pb({j, j + 1, abs(k[j][i] - k[j + 1][i])});
		}
	}

	sort(all(ks), [](vector<int>& v1, vector<int>& v2) {
		return v1[2] < v2[2];
	});

	UF uf;
	lint res = 0LL;
	
	for(int i = 0; i < ks.size(); i++) {
		if(uf.find(ks[i][0]) == uf.find(ks[i][1])) continue;
		res += ks[i][2];
		uf.unionNode(ks[i][0], ks[i][1]);
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
