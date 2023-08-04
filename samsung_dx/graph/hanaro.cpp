#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
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

typedef pair<int, int> pii;
typedef long long ll;

ll n, x, y; 
double e;

int parent[1001];

int findRoot(int x) {
	if (parent[x] != x) {
		parent[x] = findRoot(parent[x]);
	}

	return parent[x];
}

void unionRoad(int x, int y) {
	x = findRoot(x);
  y = findRoot(y);

	if(x < y) {
		parent[y] = x;
	} else {
		parent[x] = y;	
	}
}

struct info {
	ll x;
	ll y;
	int idx;

	info(int x_, int y_, int idx_) : x(x_), y(y_), idx(idx_) {}
};

struct dar {
	int idx1;
	int idx2;
	double cost;

	dar(int x_, int y_, double idx_) : idx1(x_), idx2(y_), cost(idx_) {}
};
void solve(int tn) {
	vector<info> coordinates;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}

	vector<ll> xi;
	vector<ll> yi;

	ll tmp;

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		xi.pb(tmp);
	}

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		yi.pb(tmp);
	}

	for(int i = 0; i < n; i++) {
		coordinates.pb(info(xi[i], yi[i], i));
	}

	cin >> e;

	vector<dar> candidates;

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j <  n - 1; j++)	 {
			info v1 = coordinates[i];
			info v2 = coordinates[j];

			double dist= (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y);

			candidates.pb(dar(i, j, dist));
		}
	}
	sort(candidates.begin(), candidates.end(), [] (dar first, dar second) {
		return first.cost < second.cost;	
	});

	ll res = 0;

	for(dar dar_: candidates) {
		int idx1 = dar_.idx1;
		int idx2 = dar_.idx2;
		double cost = dar_.cost;

		if(findRoot(idx1) != findRoot(idx2)) {
			unionRoad(idx1, idx2);
			res += cost;
		}
	}

	cout << "#" << tn << " " << round(res) << "\n";

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}
