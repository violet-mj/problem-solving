#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

int n, tmp;
vector<int> v;
set<int> Set;


void bt(int currValue, int currIndex) {
	for(int i = currIndex + 1; i < n; i++) {
		Set.insert(currValue + v[i]);
		bt(currValue + v[i], i);
	}
}

void solve() {
	cin >> n;
	int sum_ = 0;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		sum_ += tmp;
		v.push_back(tmp);
	}
	
	for(int i = 0; i < n; i++) {
		Set.insert(v[i]);
		bt(v[i], i);		
	}
	
	
	cout << sum_ - Set.size() << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
