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

int n, q, cmd, x, y;
string s;

void solve() {	
	cin >> n;
	vector<int> nums(n + 1, 0);		
	vector<int> prefixXor(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> nums[i];
		prefixXor[i] = prefixXor[i - 1] ^ nums[i];
	}

	cin >> s >> q;

	int curr = 0;

	for(int i = 0; i < n; i++) {
		if(s[i] == '1')	 {
			curr ^= nums[i+1];	
		}
	}

	for(int i = 0; i < q; i++) {
		cin >> cmd;	

		if(cmd == 1) {
			cin >> x >> y;
			int check = prefixXor[y] ^ prefixXor[x-1];
			curr ^= check;
		} else {
			cin >> x;	
			if(x == 0) {
				cout << (curr ^ prefixXor[n]) << " ";
			} else {
				cout << curr << " ";
			}
		}
	}
	cout <<"\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
