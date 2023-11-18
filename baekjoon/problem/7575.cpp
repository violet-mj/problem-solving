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
	short n, k, size;		
	cin >> n >> k;
	vector<vector<short>> values(n);
	short initSize;
	
	for(short i = 0; i < n; i++) {
		cin >> size;
		values[i].resize(size);
		for(short j = 0; j < size; j++) {
			cin >> values[i][j];
		}
	}

	sort(all(values), [&](vector<short>& v1, vector<short>& v2) {
				return v1.size() < v2.size();
	});

	initSize = values[0].size();

	vector<vector<short>> patterns(initSize - k + 1, vector<short>(k, 0));

	for(short i = 0; i < initSize - k + 1; i++) {
		for(short j = 0; j < k; j++) {
			patterns[i][j] = values[0][i + j];
		}
	}

	auto kmp = [&](short nthProgram, vector<short>& pattern, vector<short>& fail) {

		vector<short>& target = values[nthProgram];
		short ts = target.size();
		short ps = pattern.size();

		for(short i = 0, j = 0; i < ts; i++) {
			while(j != 0 && target[i] != pattern[j])	j = fail[j - 1];
			if(target[i] == pattern[j]) {
				if(j == ps - 1) {
					return true;	
				}
				j++;
			}
		}

		return false;
	};

	auto getFail = [&](vector<short>& pattern) {
		int ps = pattern.size();

		vector<short> fail(ps, 0);

		for(short i = 1, j = 0; i < ps; i++) {
			while(j != 0 && pattern[i] != pattern[j]) j = fail[j - 1];
			if(pattern[i] == pattern[j]) fail[i] = j + 1;
		}

		return fail;
	};

	bool flag;

	for(short i = 0; i < initSize - k + 1; i++) {
		vector<short>& pattern = patterns[i];
		vector<short> pattern1 = patterns[i];
		reverse(all(pattern1));
		vector<short> fail = getFail(pattern);
		vector<short> fail1 = getFail(pattern1);
		flag = true;
		for(short j = 1; j < n; j++) {
			if(kmp(j, pattern, fail) || kmp(j, pattern1, fail1)) {
				continue;	
			} else {
				flag = false;	
				break;
			}
		}
		if(flag) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
