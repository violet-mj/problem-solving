#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/Users/mj/.vim/template/debug.cpp"
#else
#define debug(x...)
#endif

typedef long long lint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

vector<int> erathos(int toNum) {
	int sqrtN = sqrt((lint) toNum);
	vector<bool> check(toNum + 1, true);
	for(int i = 2; i <= sqrtN; i++) {
		if(check[i]) {
			for(int j = 2 * i; j <= toNum; j += i)	 {
				check[j] = false;
			}
		}
	}

	vector<int> prime;

	for(int i = 2; i <= toNum; i++) {
		if(check[i]) {
			prime.pb(i);
		}
	}

	return prime;
}


vector<int> primes; 

void solve() {
	int n ;
	cin >> n;
	vector<int> value(n, 0);

	for(int i = 0; i < n; i++) {
		cin >> value[i];
	}

	for(auto prime: primes) {
		int k = 0;
		for(int i = 0;i < n; i++)	 {
			while(value[i] % prime == 0)	 {
				k++;	
				value[i] /= prime;
			}
		}

		if(k % n != 0) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	primes = erathos(1000001);
	for(int i = 0; i < t; i++) solve();
}
