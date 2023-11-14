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
int n;				
string s; 

char check(int curr){
	int AWin = 0;
	int BWin = 0;

	int aCnt = 0;
	int bCnt = 0;

	for(int i = 0; i < n; i++) {
		if(s[i]	== 'A') {
			aCnt++;	
		} else {
			bCnt++;	
		}

		if(aCnt == curr) {
			AWin++;	
			aCnt = 0;
			bCnt = 0;
		} else if(bCnt == curr){
			BWin++;
			aCnt = 0;
			bCnt = 0;
		}
	}

	if(aCnt == 0 && bCnt == 0) {
		if(AWin > BWin && s[n-1] == 'A') {
			return 'A';
		} else if(BWin > AWin && s[n-1] == 'B'){
			return 'B';
		}
	}
	return 'X';
}

void solve() {
	cin >> n >> s;

	for(int i = 1; i <= 20; i++) {
		char tmp = check(i);
		if(tmp != 'X') {
			cout << tmp << "\n";
			return;
		}
	}

	cout << '?' << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
		solve();
}
