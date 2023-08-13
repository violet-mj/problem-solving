#include <iostream>
#include <vector>
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

int t, q, qi;

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> arr(n);

	int minValue = 1000000009;

	for(int i = 0; i < n; i++) {
		cin >> q;	
		for(int j = 0; j < q; j++) {
			cin >> qi;
			arr[i].pb(qi);
			minValue = min(minValue, qi);
		}
	}

	for(int i = 0; i < n; i++) {
		sort(arr[i].begin(), arr[i].end());	
	}

	int minSecond = 1000000009;
	long long res = 0;

	for(int i = 0; i < n; i++) {
		minSecond = min(minSecond, arr[i][1]);
		res += arr[i][1];
	}

	res = res - minSecond + minValue;

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
