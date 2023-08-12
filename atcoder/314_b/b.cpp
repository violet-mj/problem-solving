
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

int n, c, ai, x;

void solve() {
	cin >> n;

	vector<vector<int>> people(n);

	for(int i = 0; i < n; i++) {
		cin	>> c;
		for(int j = 0; j < c; j++){
			cin >> ai;
			people[i].pb(ai);
		}
	}

	cin >> x;

	vector<pair<int, int>> res;

	int max_ = 1000000000;

	for(int i = 0; i < n; i++) {
		for(int v: people[i])	{
			if(v == x) {
				res.pb(mp(i+1, people[i].size()));
				max_ = people[i].size() < max_ ? people[i].size() : max_ ;
				break;
			}	
		}
	}

	vector<int> result;

	for(pair<int, int> k: res) {
		if(k.second == max_)	 {
			result.pb(k.first);
		}
	}

	cout << result.size() << "\n";
	for(int rrr: result) {
		cout << rrr << " ";	
	}
	cout <<"\n";

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
