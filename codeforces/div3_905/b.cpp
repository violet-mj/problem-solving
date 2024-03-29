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
	int n, k;	
	cin >> n >> k;
	string s;
	cin >> s;

	vector<int> alpha(26, 0);

	for(int i = 0; i < s.size(); i++) {
		alpha[s[i] - 'a']++;
	}

	int oc = 0;

	for(int i = 0; i < 26; i++){
		if(alpha[i] % 2 == 1)	 {
			oc++;	
		}
	}

	if(oc - k <= 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
		solve();
}
