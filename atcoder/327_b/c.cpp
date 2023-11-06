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
	int k[9][9];

	for(int i = 0; i < 81; i++)	 {
		cin >> k[i / 9][i % 9];
	}

	for(int i = 0; i < 9; i++) {
		set<int> check;
		for(int j = 0; j < 9; j++)	 {
			check.insert(k[i][j]);
		}
		if(check.size() != 9) {
			cout << "No\n";
			return;
		}
	}
	for(int i = 0; i < 9; i++) {
		set<int> check;
		for(int j = 0; j < 9; j++)	 {
			check.insert(k[j][i]);
		}
		if(check.size() != 9) {
			cout << "No\n";
			return;
		}
	}

	for(int i = 0; i < 9; i+=3) {
		for(int j = 0; j < 9; j+=3)		 {
			set<int> check;	
			for(int x = 0; x < 3; x++) {
				for(int y = 0; y < 3; y++) {
					check.insert(k[i+x][j+y]);
				}
			}

			if(check.size() != 9) {
				cout << "No\n";
				return;
			}
		}
	}

	cout << "Yes\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
