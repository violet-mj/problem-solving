#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

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
	int n, k, size;		
	cin >> n >> k;
	vector<vector<int>> values(n, vector<int>());
	vector<vector<bool>> check;
	int initSize;
	
	for(int i = 0; i < n; i++) {
		cin >> size;
		if(i == 0) {
			check.resize(n, vector<bool>(size - k + 1, false));
			initSize = size;
		}
		values[i].resize(size);
		for(int j = 0; j < size; j++) {
			cin >> values[i][j];
		}
	}

	for(int i = 0; i < initSize; i++)  {
		check[0][i]	= true;
	}

	vector<vector<int>> patterns(initSize - k + 1, vector<int>(k, 0));

	for(int i = 0; i < initSize - k + 1; i++) {
		for(int j = 0; j < k; j++)		 {
			patterns[i][j] = values[0][i + j];
		}
	}

	debug(patterns);
	return;

	auto kmp = [&](int nthProgram, vector<int>& pattern, vector<int>& fail) {

		vector<int> target = values[nthProgram];
		int ts = target.size();

		for(int i = 1, j = 0; i < ts; i++) {
			while(j != 0 && target[i] != target[j])	j = fail[j - 1];

		}

		return true;
	};

	auto getFail = [&](vector<int>& pattern) {
		int ps = pattern.size();

		vector<int> fail(ps, 0);

		for(int i = 1, j = 0; i < ps; i++) {
			while(j != 0 && pattern[i] != pattern[j]) j = fail[j - 1];
			if(pattern[i] == pattern[j]) fail[i] = j + 1;
		}

		return fail;
	};

	for(int i = 0; i < initSize - k + 1; i++) {
		vector<int> pattern = patterns[i];
		vector<int> fail = getFail(pattern);
		for(int j = 1; j < n; j++) {
			bool isExist = kmp(j, pattern, fail);
			check[j][i] = isExist ? true : false;
		}
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
