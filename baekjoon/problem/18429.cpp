#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

int c = 0;
int n, k;
vector<int> vec;
vector<bool> visited;

void backtracking(int index, int currMus) {

	if(index == n - 1) c++;

	for(int i = 0; i < n; i++) {
		if(!visited[i] && currMus + vec[i] - k >= 500) {
			visited[i] = true;
			backtracking(index + 1, currMus + vec[i] - k);
			visited[i] = false;
		}
	}
}

void solve() {
	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		int tmp;	
		cin >> tmp;
		vec.pb(tmp);
		visited.pb(false);
	}

	for(int i = 0; i < n; i++) {
		if(!visited[i] && vec[i] - k >= 0)	 {
			visited[i] = true;	
			backtracking(1, 500 + vec[i] - k);
			visited[i] = false;
		}
	}
	cout << c << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
