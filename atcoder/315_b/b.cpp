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

int n, t;

void solve() {
	cin >> n;
	vector<int> cal(n);
	int sum_ = 0;
	for(int i = 0; i < n; i++) {
		cin >> cal[i];
		sum_ += cal[i];
	}

	vector<int> prefixSum(n + 1);
	prefixSum[0] = 0;
	prefixSum[1] = cal[0];

	for(int i = 2; i <= n; i++) {
		prefixSum[i] = prefixSum[i-1] + cal[i - 1];
	}

	int findValue = (sum_ + 1) / 2;

	int l = 0;
	int r = n + 1;

	while(l + 1 < r) {
		int mid = (l + r) >> 1;	
		
		if(prefixSum[mid] == findValue) {
			cout << mid  << " " << findValue - prefixSum[mid-1] << "\n";
			return;
		}

		if(prefixSum[mid] < findValue) {
			l = mid;	
		} else {
			r = mid;
		}
	}

	debug(prefixSum, cal, sum_, findValue, l);

	cout << l + 1  << " " << findValue - prefixSum[l] << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
