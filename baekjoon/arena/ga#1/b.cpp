#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>


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

int n, m;
string tmp, cadi;
set<string> ss;
vector<string> store;
vector<string> candidates;

void solve() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		store.pb(tmp);
		ss.insert(tmp);
	}

	cin >> m;

	for(int i = 0; i < m; i++) {
		cin >> tmp;	

		candidates.pb(tmp);
	}

	if(n == 1) {
		cout << candidates[0] << "\n";	
		return;
	}

	for(int i = 0; i < n; i++){
		if(store[i].compare("?") == 0) {
			if(i == 0) {
				for(auto candidate: candidates) {
					if(store[i+1][0] == candidate[candidate.size() - 1] && ss.find(candidate) == ss.end()) {
						cout << candidate << "\n"	;
						return;
					}
				}
			} else if(i == n - 1) {
				for(auto candidate: candidates) {
					if(store[i-1][store[i-1].size()-1] == candidate[0] && ss.find(candidate) == ss.end())	 {
						cout << candidate << "\n";
						return;
					}
				}	
			} else {
				for(auto candidate: candidates) {
					if(store[i-1][store[i-1].size()-1] == candidate[0] && store[i+1][0] == candidate[candidate.size() - 1] && ss.find(candidate) == ss.end()) {
						cout << candidate << "\n";
						return;
				}	
			}				
		}
	}	
}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
