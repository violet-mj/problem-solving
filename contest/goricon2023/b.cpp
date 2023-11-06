
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

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
typedef tuple<int,int,string> ti;

#define pb push_back
#define mp make_pair
#define mt make_tuple
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

void printRes(int a, int b, string vec) {
	cout << a;
	cout << vec;
	cout << b << "\n";
	return;
}

void solve() {
	int a, b, n;
	cin >> a >> b >> n;
	map<int, vector<int>> m;
	vector<vector<int>> visited(n, vector<int>(10, 0));
	vector<int> primes = erathos(100)	;

	for(int i = 0; i < primes.size(); i++) {
		if(primes[i] > 10) {
			int f = primes[i] / 10;	
			int s = primes[i] % 10;
			m[f].push_back(s);
		}
	}

	
	queue<ti> q;
	q.push(mt(2, a % 10, ""));

	while(!q.empty()) {
		auto [depth, value, vec]	= q.front();
		debug(depth, value, vec);
		q.pop();
		if(visited[depth][value]) continue;
		visited[depth][value] = true;
		if(depth == n - 2) {
			int nnn = value * 10 + b / 10;
			if(find(all(primes), nnn) != primes.end()) {
				printRes(a, b, vec);
				return;
			}
		}
			
		if(depth > n - 2)	break;

		for(auto i: m[value]) {
			q.push(make_tuple(depth + 1, i, vec + to_string(i)));
		}
	}

	cout << -1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
