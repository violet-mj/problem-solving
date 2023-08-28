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

int n, t;

typedef vector<vector<int>> vvi;

const int MOD = 1000000;

vvi k(vvi& t1, vvi& t2) {
	vvi mRes(2, vector<int>(2, 0));
	
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			for(int z = 0; z <2; z++) {
				lint kk = mRes[i][j] + ((lint)t1[i][z] * (lint)t2[z][j]) % MOD;
				kk %= MOD;
				mRes[i][j] += kk;
			}
		}
	}

	return mRes;
}


vvi matMul(vvi a, int b) {
	if(b == 0) {
		return {{1, 0}, {0, 1}};
	}

	vvi tmp = matMul(a, b/2);

	vvi eee = k(tmp, tmp);

	if(b % 2 == 1) {
		return k(eee, a);
	} else {
		return eee;	
	}
}

void solve() {
	cin >> n;
	vvi init = {{1, 1}, {1, 0}};

	if(n <= 1) {
		cout << n << "\n";
		return;
	}
	vvi result = matMul(init, n-1);

	cout << result[0][0] << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
