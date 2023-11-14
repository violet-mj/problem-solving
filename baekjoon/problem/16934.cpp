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

struct Trie {
	Trie *nxt[26];
	int count;

	Trie(): count(0) {
		fill(nxt, nxt+ 26, nullptr);
	}

	~Trie() {
		for(int i = 0; i < 26; i++) {
			if(nxt[i]) delete nxt[i];
		}
	}

	void insert(char* str, bool already) {
		if(*str == '\0')	{
			count++;	
			if(already && count != 1) cout << (count == 1 ? "" : to_string(count)) << "\n";
			return;
		} else {
			if(!nxt[*str-'a'])	{
				if(already)cout << *str << "\n";
				already = false;
				nxt[*str-'a'] = new Trie;
			}
		}
		if(already) cout << *str;
		nxt[*str-'a']->insert(str + 1, already);
	}
};

void solve() {
	int n;
	cin >> n;
	Trie* root = new Trie;
	for(int i = 0; i < n; i++) {
		char tmp[11];
		cin >> tmp;
		root->insert(tmp, true);
	}
	delete root;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
