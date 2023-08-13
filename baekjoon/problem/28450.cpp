#include <iostream>
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

template<typename T>
T ceil(T a, T b) {
	return (a - 1) / b + 1;
}

int n,m,t,h;

void solve() {
	cin >> n >> m;

	ll graph[n][m];
	ll dp[n][m];

	fill(&dp[0][0], &dp[n-1][m], 0);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> graph[i][j];
	cin >> h;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i == 0 && j == 0) {
				dp[i][j] = graph[i][j];
				continue;
			}

			if(j - 1 >= 0 && i - 1 >= 0) {
				dp[i][j] = min(dp[i][j-1] + graph[i][j], dp[i-1][j] + graph[i][j]);
			}

			if(i - 1 >= 0 && j == 0) {
				dp[i][j] = dp[i-1][j] + graph[i][j];
			}

			if(j-1>=0 && i == 0) {
				dp[i][j] = dp[i][j-1] + graph[i][j]	;
			}

		}
	}

	cout << (dp[n-1][m-1] <= h ? "YES\n" : "NO\n");

	if(dp[n-1][m-1] <= h) {
		cout << dp[n-1][m-1] << "\n"	;
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++)
	solve();
}
