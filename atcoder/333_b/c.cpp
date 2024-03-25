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
	int n;				
	cin >> n;

	vector<lint> pre1(14, 0);
	pre1[1] = 1;
	for(int i = 2; i < 14; i++) {
		pre1[i] = pre1[i-1] * 10LL + 1LL;	
	}
	int cnt = 0;
	for(int i = 1; i < 13; i++) {
		for(int j = 1; j <= i; j++)	 {
			for(int z = 1; z <= j; z++)	 {
				cnt++;
				if(cnt == n) {
					cout << (pre1[i] + pre1[j] + pre1[z])	<< "\n";
					return;
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
