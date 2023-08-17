#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>

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

int n, m, t;
	
pii dirs(char direction) {
	if(direction == 'D') {
		return mp(1, 0);
	} else if(direction == 'U') {
		return mp(-1, 0);
	} else if (direction == 'R') {
		return mp(0, 1);
	} else  {
		return mp(0, -1);
	}
}

void solve() {
	cin >> n >> m;

	int dp[n][m];
	char graph[n][m];
	bool visited[n][m];

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> graph[i][j];

	fill(&dp[0][0], &dp[n-1][m], -1);

	bool flag;

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
		int cx = i;
		int cy = j;
		debug(i, j);

		if(dp[i][j] != -1) {
			continue;		
		};

		flag = true;

		vector<pii> tmp;

		while(cx >= 0 && cx < n && cy >= 0 && cy < m) {

			debug(cx, cy);

			if(dp[cx][cy] == -2) {
				flag = 0;	
				break;
			}

			if(dp[cx][cy] != -1) {
				flag = dp[cx][cy];
				break;
			}


			tmp.pb(mp(cx, cy));
			dp[cx][cy] = -2;

			pii nd = dirs(graph[cx][cy]);

			cx += nd.first;
			cy += nd.second;
		}

		for(pii valuep: tmp) {
			dp[valuep.first][valuep.second] = flag;	
		}
	}

	int cnt = 0;

	for(int i =0 ; i < n; i++) for(int j = 0; j < m; j++) {
		if(dp[i][j] == 1) cnt++	;
	}

	cout << cnt << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
