
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

typedef long long lint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

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
double prime;

lint gcd(lint a, lint b) {
	while(b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

void solve() {
	cin >> prime;

	ld check = (ld)1/10000000;
	ld limit = (ld)1/1000000000;
	debug(check);

	pdd l = mp(0, 1);
	pdd r = mp(1, 1);
	int cnt = 10;

	while(1) {
		lint k = gcd(l.second, r.second);
		lint kk = l.second * r.second / k;

		debug(k, kk, l, r);

		lint first = l.first * (kk / l.second);
		lint second = r.first * (kk / r.second);

		lint mid = (first + second);


		debug(mid, first, second);
		if(mid % 2 == 0) {
		  mid /= 2;		
		} else {
			kk *= 2;	
		}

		ld midk = (ld)mid / (ld)kk;
		debug(midk);

		debug(midk - prime);

		if(mid == 0) {
			break;	
		}
		if(abs(midk - prime) <= check) {
			cout << "YES\n";
			lint gcdRe = gcd(mid, kk);
			cout << mid / gcdRe << " " << kk / gcdRe << "\n";
			return;
		}
	
		if(midk < prime) {
			l = mp(mid, kk);
		} else {
			r = mp(mid, kk);
		}
	}
	cout << "NO\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
