#include <iostream>
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

lint n, t, a, b;
vector<pll> v;

void solve() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a >> b;	
		v.pb(mp(a, b));
	}
	lint min_ = 1LL << 60;

	lint resx = -1;
	lint resy = -1;

	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++)	 {
			lint tmp = 0;
			for(int z = 0; z < n; z++)	 {
				lint kk =  (v[z].second - (i * v[z].first + j));
				tmp += kk * kk;
			}
			if(tmp < min_) {
				min_ = tmp;	
				resx = i;
				resy = j;
			}
		}
	}
	cout << resx << " " << resy << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
