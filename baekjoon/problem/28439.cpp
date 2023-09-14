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
typedef tuple<int, int, int> tiii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

int n, m;

void solve() {
	cin >> n >> m;	
	vector<vector<int>>	matrix(n, vector<int>(m, 0));
	vector<int> check;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<int> fRow(n);
	vector<int> fCol(m);

	for(int i = 0; i < n; i++) {
		check.pb(matrix[0][0] - matrix[i][0]);
		fRow[i] = matrix[i][0];
	}

	for(int i = 0; i < m; i++) {
		check.pb(matrix[0][i]);
		fCol[i] = matrix[0][i];
	}

	sort(all(check));
	
	int checkSize = check.size();

	int curr = check[0];
	int	count = 1; 
	int currMax = check[0];
	int maxCount = 0;

	for(int i = 1; i < checkSize; i++) {
		if(curr == check[i]) {
			count++;	
		} else {
			if(count > maxCount) {
				maxCount = count;	
				currMax = curr;
			}
			curr = check[i];
			count = 1;
		}
	}
	
	if(count > maxCount) {
		currMax = curr;	
	}

	vector<int> operR;
	vector<int> operC;

	vector<tiii> res;
	debug(currMax);
	int rowAdd = matrix[0][0] - currMax;
	operR.pb(currMax);
	if(currMax!= 0) {
		res.pb(mt(1, 1, currMax));
	}
	operC.pb(rowAdd);
	if(rowAdd != 0) {
		res.pb(mt(2, 1, rowAdd));
	}
	for(int i = 1; i < n; i++) {
		operR.pb(operR[0] + fRow[i] - fRow[0]);
		if(operR[i] != 0) {
			res.pb(mt(1, i+1, operR[i]));
		}
	}


	for(int i = 1; i < m; i++) {
		operC.pb(operC[0] + fCol[i] - fCol[0]);
		if(operC[i] != 0) {
			res.pb(mt(2, i+1, operC[i]));
		}
	}

	debug(operR, operC);
	debug(check);

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++)	 {
			if(matrix[i][j] != operR[i] + operC[j])	 {
				cout << -1 << "\n";
				return;
			}
		}
	}

	cout << res.size() << "\n";
	for(auto [operation, index, value]: res) {
		cout << operation << " " << index << " " << value << "\n";
	}
}



int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
