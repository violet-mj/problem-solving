
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

typedef long long lint;

int n, t;

void solve() {
	cin >> n;
	int arr[n];

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if(n == 1) {
		cout << 1 << "\n";
		return;
	}

	int l = 0;
	int r = 1;
	lint currA = arr[l] + arr[r];
	lint currM = arr[l] * arr[r];
	int cnt = 0;

	while(l != n - 1 && r != n - 1) {
		debug(l, r, currM, currA);
		if(currM == currA)	 {

			if(l != r) cnt++;
			r++;
			currA += arr[r];
			currM *= arr[r];
		} else if(currM > currA || currM) {
			currA -= arr[l];
			currM /= arr[l];
			l++;
		} else {
			if(r == n - 1) {
				currA -= arr[l];
				currM /= arr[l];
				l++;	
				continue;
			}
			r++;
			currA += arr[r];
			currM *= arr[r];
		}
	}

	cout << n + cnt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
