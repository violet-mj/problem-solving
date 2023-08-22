
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

int n, t, tmp;
vector<int> prefixSum1;
vector<int> prefixSum2;
vector<int> cards;

void solve() {
	cin >> n;

	cards.pb(0);
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		cards.pb(tmp);
	}
	debug(cards);
	prefixSum1.pb(0);
	prefixSum1.pb(cards[1]);
	for(int i = 2; i <= n + 1; i++) {
		if(i % 2 == 1) {
			prefixSum1.pb(prefixSum1[i-2] + cards[i]);
		} else {
			prefixSum1.pb(prefixSum1[i-1]);
		}
	}
	prefixSum2.pb(0);
	prefixSum2.pb(0);
	for(int i = 2; i <= n + 1; i++) {
		if(i % 2 == 0) {
			prefixSum2.pb(prefixSum2[i-2] + cards[i]);
		} else {
			prefixSum2.pb(prefixSum2[i-1]);
		}
	}
	int max_ = -1;
	debug(prefixSum1);
	debug(prefixSum2);

	for(int i = 0; i <= n; i++) {
		int tmp = 0;	
		tmp += (prefixSum1[i] - prefixSum1[0]);
		if(i % 2 == 0) {
			tmp += (prefixSum2[n] - prefixSum2[i]);
		} else {
			tmp += (prefixSum2[n-1] - prefixSum2[i]);
		}
		max_ = max(max_, tmp);
		debug(tmp);
	}

	cout << max_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
