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

const int MAX_STR = 100001;
const int ROOT = 1;
	int trie[MAX_STR][26];
	int isEnd[MAX_STR];

void printArray(int arr[MAX_STR][26]) {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 26; j++)	 {
			cout << arr[i][j] << " ";	
		}
		cout << "\n";
	}
}

void solve() {
	int n;
	cin >> n;
	vector<string> values(n);
	int unused = 1;

	auto ctoi = [](char tc) {
		return tc - '0';
	};

	for(int i = 0; i < n; i++) cin >> values[i];

	fill(&trie[0][0], &trie[MAX_STR-1][26], -1);
	fill(&isEnd[0], &isEnd[MAX_STR], 0);

	auto insert = [&](string& v) {
		int curr = ROOT;	
		bool isPos = true;
		for(int i = 0; i < v.size(); i++) {
			//printArray(trie);
			char c = v[i];
			int ci = ctoi(c);
			// debug(curr, c, ci, isEnd[curr]);
			if(isEnd[curr]) {
				isPos = false;
			}
			if(trie[curr][ci] == -1) {
				trie[curr][ci] = ++unused;
			}
			curr = trie[curr][ci];
		}
		isEnd[curr] = 1;
		return isPos;
	};

	auto find = [&](string& v) {
		int curr = ROOT;	
		
		for(int i = 0; i < v.size(); i++) {
			char c = v[i];
			int ci = ctoi(c);
			if(trie[curr][ci] == -1) return true;
			if(isEnd[curr]) return false;
			curr = trie[curr][ci];
		}
		return true;
	};

	for(int i = 0; i < n; i++) {
		insert(values[i]);
	}

	for(int i = 0; i < n; i++) {
		if(!find(values[i])) {
			cout << "NO\n";
			return;
		}
	}



	cout << "YES\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
		solve();
}
