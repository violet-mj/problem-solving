#include <iostream>
#include <vector>
#include <queue>
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

int n, t, cmd, tmp;
bool visited[200001];
vector< vector<int> > graph(200001);
vector<int> result;


void dfs(int curr) {
	visited[curr] = true;	
	for(int i = 0; i < graph[curr].size(); i++) {
		if(!visited[graph[curr][i]]) dfs(graph[curr][i]);
	}
	result.pb(curr);
}

void solve() {
	cin >> n;
	fill(&visited[0], &visited[200001], false);

	for(int i = 1; i < n + 1; ++i) {
		cin >> cmd;	
		if(cmd == 0) continue;
		
		for(int j = 0; j < cmd; j++) {
			cin >> tmp;
			graph[i].pb(tmp);
		}
	}
	dfs(1);

	for(int i = 0; i < result.size(); i++) {
		if(result[i] == 1) break;
		cout << result[i] << " ";
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
