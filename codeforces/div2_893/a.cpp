#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

template<typename T>
T ceil(T a, T b) {
	return (a - 1) / b + 1;
}

int a,b,c, t;

void solve() {
	cin >> a >> b >> c;

	if(c % 2 == 0) {
		if(a > b)	 {
			cout << "First\n";
		} else {
			cout << "Second\n";
		}
	} else {
		if(a < b)	 {
			cout << "Second\n";
		} else {
			cout << "First\n";
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
}
