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

int a, b;



vector<int> erathos(int toNum) {
	int sqrtN = sqrt((ld) toNum) + 12;
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

void solve() {
	cin >> a >> b;		
	vector<int> era = erathos(10000);
	int ar = a % 2;
	int arr = a + (2 - ar) % 2;
	if(arr == 2) {
		arr += 2;	
	}
	if(arr <= b) {
		cout << arr / 2 << " " << arr / 2 <<"\n";
		return;
	} 

	if(b - a != 0) {
		cout << -1 << "\n";
		return;
	}

	for(int e: era) {
		if(a % e == 0)	 {
			if(e <= 1 || a - e <= 1) continue;
			cout << e << " " << a - e << "\n";
			return;
		}
	}

	cout << -1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
