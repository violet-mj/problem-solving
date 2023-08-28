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
string s;

void solve() {
	cin >> n >> m;
	cin >> s;

	if(m % 2 == 0) {
		sort(s.begin(), s.end());
		cout << s << "\n";
	} else {
		vector<char> v1;	
		vector<char> v2;

		for(int i = 0; i < n; i++) {
			if(i % 2 == 0) {
				v1.pb(s[i]);
			} else {
				v2.pb(s[i]);
			}
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		vector<char> res;

		for(int i = 0; i < n; i++) {
			if(i % 2 == 0)	 {
				res.pb(v1[i/2]);
			} else {
				res.pb(v2[i/2]);	
			}
		}

		for(int i = 0; i < n; i++) {
			cout << res[i];
			if(i == n - 1) {
				cout << "\n";
			}
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
