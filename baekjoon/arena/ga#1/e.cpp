#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair
#define pb push_back
#define f first
#define s second

int n, k, tmp;
long long candi[100000];
long long exp2r[100001];
const long long MOD = 1000000007;

int ceil(int a, int b) {
	return (a - 1) / b + 1;
}

void solve() {
	cin >> n >> k;
	fill(candi, &candi[100000], 0);
	fill(exp2r, &exp2r[100001], 0);
	exp2r[0] = 1;

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		candi[tmp % k] = candi[tmp%k] + 1;
	}

	long long remainder = 0;
	for(int i = 0; i < k; i++) {
		remainder += candi[i];
	} 

	for(int i = 1; i < 100001; i++) {
		exp2r[i] = (exp2r[i-1] * 2) % MOD;
	}

	long long res = 1;
	for(int i = 0; i < ceil(k, 2); i++) {
		if(i == 0) {
			res *= (candi[0] + 1);
			res %= MOD;
		} else {
			long long i1 = candi[i];
			long long i2 = candi[k-i];
			long long tmps = (exp2r[i1] + exp2r[i2]- 1) % MOD;
			res *= tmps;
			res %= MOD;
		}
	}

	if(k % 2 == 0) {
		res *= candi[k/2] + 1;
		res %= MOD;
	}
	cout << (res + MOD - remainder - 1) % MOD << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
