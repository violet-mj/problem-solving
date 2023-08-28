#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
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

template<typename T>
T ceil(T a, T b) {
	return (a - 1) / b + 1;
}

int n, x, y, z, t;

struct store {
	int diff;
	int z;
	store(int diffs, int zz): diff(diffs), z(zz) {}
};

void solve() {
	cin >> n;
	vector<store> v;
	int sumZ = 0;
	int currZ = 0;
	for(int i = 0; i < n; i++) {
		cin >> x >> y >> z;	
		sumZ += z;
		if(x > y) {
			currZ += z;		
			int mid = (x + y) / 2 + 1;
			v.pb(store(x - mid, z));
		}
	}

	int sumZ2 = sumZ / 2 + 1;
	int diffValue = sumZ2 - currZ;

	if(diffValue <= 0) {
		cout << 0 << "\n"	;
		return;
	}
	int dp[v.size() + 1][diffValue + 1];
	fill(&dp[0][0], &dp[v.size()][diffValue + 1], 0);

	for(int i = 1; i <= v.size(); i++) {
		for(int j = v[i].z; j <= diffValue; j++)	 {
			dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i].z] + v[i-1].diff);
		}
	}

	cout << dp[v.size()][diffValue] << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
