#include <iostream>
#include <vector>
#include <cmath>
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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()



int erathos(int toNum, int k) {
	int sqrtN = (int)sqrt(toNum);
	vector<int> check(toNum + 1, 1);
	int cnt = 0;
	for(int i = 2; i <= toNum ; i++) {
		if(check[i]) {
			for(int j = i; j <= toNum; j += i)	 {
				if(!check[j]) continue;
				check[j] = 0;
				debug(j);
				cnt++;
				if(cnt == k) {
					return j;
				}
			}
		}
	}
	debug(check);
	return -1;
}

void solve() {
	int n, k;
	cin >> n >> k	;
	cout << erathos(n, k) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
