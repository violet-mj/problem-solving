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

int n, t;

void solve() {
	cin >> n;
	vector<int> v(n);

	for(int i = 0; i < n; i++) cin >> v[i];

	reverse(v.begin(), v.end());

	if(v[0] == 1) {
		cout << "NO\n";
		return;
	}

	vector<int> res;
	int oc = 0;

	for(int i = 0; i < n - 1; i++) {
		if(v[i] == 0 && v[i + 1] == 0) {	
			res.pb(0);
		} else if(v[i] == 1 && v[i+1] == 0) {
			res.pb(oc);
			oc = 0;
		} else if(v[i] == 1 && v[i+1] == 1) {
			res.pb(0);
			oc++;
		} else {
			res.pb(0);
			oc++;
		}
	}

	res.pb(oc);

	cout << "YES\n";
	for(int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	cin >> t;
	for(int i = 0; i < t; i++)  solve();
}
