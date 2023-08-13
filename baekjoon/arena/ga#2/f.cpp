#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
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
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
 
unordered_map<char, function<int(int, int)>> m;
 
template<typename T>
T ceil(T a, T b) {
	return (a - 1) / b + 1;
}
 
int n, t;
char c1, c2;
int d1, d2;
 
 
void solve() {
	cin >> n;
	int dp[n+1][7];

	fill(&dp[0][0], &dp[n][7], 0);
 
	m['*'] = [](int x, int y) {return x * y % 7;};
	m['+'] = [](int x, int y) {return (x + y) % 7;};
	dp[0][1] = 1;
 
	for(int i = 0; i < n; i++) {
		cin	>> c1 >> d1 >> c2 >> d2;
		for(int j = 0; j < 7; j++) {
			if(dp[i][j] == 1) {
				dp[i+1][m[c1](j, d1)] = 1;
				dp[i+1][m[c2](j, d2)] = 1;
			}
		}
	}
 
	if(dp[n][0] == 1) {
		cout << "LUCKY" << "\n";
	} else {
		cout << "UNLUCKY" << "\n";
	}
}
 
int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	cin >> t;
	for(int i = 0; i < t; i++)
	solve();
}
