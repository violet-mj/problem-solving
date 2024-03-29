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

int n, m, t;
lint d;

void solve() {
	cin >> n >> m >> d;
	int k[n];
	debug();

	priority_queue<int, vector<int>, greater<int>> pq;
	lint kSum = 0;
	lint res = 0;
	for(int i = 0; i < n; i++) cin >> k[i];

	for(lint i = 1; i <= n; i++) {
		debug(k[i-1], kSum, i, d);
		lint tmp = k[i-1] + kSum - i * d; 	
		if(tmp > 0) {
			res = max(res, tmp);
		}

		if(pq.size() < m - 1) {
			if(k[i-1]	> 0) {
				pq.push(k[i-1]);
				kSum += k[i-1];
			}
		} else {
			if(m == 1) continue;
			if(k[i-1]	> pq.top()) {
				kSum += (k[i-1] - pq.top());
				pq.pop();
				pq.push(k[i-1]);
			}
		}
	}

	cout << res << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
