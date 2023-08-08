#include <iostream>
#include <map>
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

ll n, t, tmp, q, x, y;

ll preciseSqrt(ll value) {
	ll l = 0;
	ll r = 2000000000;
	while(l + 1 < r) {
		ll mid = (l + r) >> 1;	
		
		if(mid * mid <= value) {
			l = mid;	
		} else {
			r = mid;	
		}
	}
	return l;
}

void solve() {
	cin >> n;
	map<ll, ll> m;

	for(int i = 0; i < n; i++) {
		cin >> tmp;		
		m[tmp]++;
	}
	cin >> q;

	for(int i = 0; i < q; i++) {
		cin >> x >> y;	
		ll xy = x * x - 4 * y;
		if(xy < 0) {
			cout << 0 << " ";		
			continue;
		}
		ll sqrtxy = preciseSqrt(xy);

		ll x1 = (x + sqrtxy);
		ll x2 = (x - sqrtxy);

		ll res = 0;

		if(x1 % 2 == 0) {
			x1 /= 2;
			ll mx1 = m[x1];
		  if(x1 == x - x1) {
			  res += ((mx1) * (m[x1] - 1) / 2);	
		  } else {
			  res += (mx1) * (m[x - x1]);
		  }
		}

		if(x2 % 2 == 0) {
			x2 /= 2;
			ll mx2 = m[x2];
		  if(x2 == x - x2) {
			  res += ((mx2) * (mx2 - 1) / 2);	
		  } else {
			  res += (mx2) * (m[x - x2]);
		  }
		}
		cout << res / 2 << " ";
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
