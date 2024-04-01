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

void solve() {
	int a, b, c; cin >> a >> b >> c;	
	if(c != a + 1) {
		cout << -1 << "\n";
		return;
	}

	if(a == 0) {
		cout << b << "\n";
		return;
	}

	int check = -1;
	for(int i = 31; i >= 0; i--) {
		if(((a + 1)& (1 << i) )> 0) {
			check = i; break;	
		}
	}

	int sub = (1 << check) - 1;
	
	int remainA = a - sub;
	int remainB = (1 << check) - remainA;

	int nxt = a + 1;

	debug(remainA, remainB);

	if(((a + 1) & a) == 0 && b == 0) {
		cout << check << "\n";
		return;
	}
	b -= remainB;	
	cout << check + 1 + (b + nxt - 1) / nxt << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
