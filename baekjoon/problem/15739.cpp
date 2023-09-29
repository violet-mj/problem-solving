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
	int matrix[n][n];
	set<int> duplicate;
	bool check = true;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)	 {
			cin >> matrix[i][j];
			if(duplicate.find(matrix[i][j]) != duplicate.end()) {
				check = false;
			}
			duplicate.insert(matrix[i][j]);
		}
	}

	if(!check) {
		cout << "FALSE\n";
		return;
	}
	const int magicSquare = n * (n * n + 1) / 2;
	debug(magicSquare);
	int sum_ = 0;	
	for(int i = 0; i < n; i++) {
		sum_ = 0;
		for(int j = 0; j < n; j++) {
			sum_+=matrix[i][j];
		}

		if(sum_ != magicSquare) {
			cout << "FALSE\n";
			return;
		}

		sum_ = 0;
		for(int j = 0; j < n; j++) {
			sum_+=matrix[j][i];
		}

		if(sum_ != magicSquare) {
			cout << "FALSE\n";
			return;
		}
	}

	sum_ = 0;
	for(int i = 0; i < n; i++) {
		sum_ += matrix[i][i];
	}
	if(sum_ != magicSquare) {
		cout << "FALSE\n";
		return;
	}
	sum_ = 0;
	for(int i = 0; i < n; i++) {
		sum_ += matrix[i][n - i - 1];
	}
	if(sum_ != magicSquare) {
		cout << "FALSE\n";
		return;
	}
	
	cout << "TRUE\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
