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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

void solve() {
	string s, t;
	int n, m;		
	cin >> n >> m >> s >> t;
	char initN = s[0];
	bool flag = true;
	for(int i = 1; i < n; i++) {
		if(s[i] != initN) {
			initN = s[i];
		} else {
			flag = false;
			break;	
		}
	}

	if(flag) {
		cout << "Yes\n";
		return;
	}

	int initT = t[0];
	flag = true;
	for(int i = 1; i < m; i++) {
		if(t[i] != initT)	{
			initT = t[i];
		} else {
			flag = false;	
			break;
		}
	}

	char tfe;

	if(t[0] != t[m - 1]) {
		flag = false;	
	} else {
		tfe = t[0];
	}

	if(!flag) {
		cout << "No\n";
		return;
	}

	for(int i = 0; i < n - 1; i++) {
		if(s[i] != s[i+1])	 {
			continue;	
		} else {
			if(s[i] == '0')	 {
				if(s[i] == tfe) {
					cout << "No\n";	
					return;
				}
			} else {
				if(s[i] == tfe) {
					cout << "No\n";
					return;
				}	
			}
		}
	}

	cout << "Yes\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)  solve();
}
