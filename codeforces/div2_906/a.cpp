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
	int n;		
	cin >> n;
	vector<int> values(n);

	for(int i = 0; i < n; i++) cin >> values[i];
	
	set<int> set_;

	for(int i = 0; i < n; i++) {
		set_.insert(values[i]);
	}

	if(set_.size() > 2) {
		cout << "No\n";
		return;
	}

	sort(all(values));

	int i1 = values[0];
	int i2 = values[values.size() - 1];
	int s1 = 0;
	int s2 = 0;

	for(int i = 0; i < n; i++) {
		if(values[i] == i1)	{
			s1++;	
		}

		if(values[i] == i2) {
			s2++;
		}
	}
	debug(i1, s1, i2, s2);

	if(abs(s1 - s2) <= 1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}
int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)  solve();
}
