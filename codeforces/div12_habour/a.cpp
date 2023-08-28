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

int t;
int a1, an, n;

void solve() {
	cin >> a1 >> an >> n;

	vector<int> v(n, 0);

	v[0] = a1;
	v[n-1] = an;

	for(int i = 1; i <= n - 2; i++) {
		v[n-1-i] = v[n-i]	- i;
		
	}

	vector<int> d;
	vector<int> cd;

	for(int i = 0; i < n - 1; i++) {
		d.pb(v[i+1] - v[i]);
		cd.pb(v[i+1] - v[i]);
	}

	int curr = 1000000009;

	for(int i = 0; i < n - 1; i++) {
		if(curr > d[i]) {
			curr = d[i];
		} else {
			cout << -1 << "\n";
			return;
		}
	}

	for(int i = 0; i < n; i++) {
		cout << v[i] << " \n"[i == n - 1];
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
