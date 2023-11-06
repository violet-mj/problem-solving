#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdio>

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
	bool output;
	int branch;
	int words;

	Trie(): output(false), branch(0), words(0) {
		fill(nxt, nxt+26, nullptr);
	}

	~Trie(){
		for(int i = 0; i < 26; i++)	{
			if(nxt[i]) delete nxt[i];
		}
	}

	void insert(char *st) {
		if(*st == '\0') {
			branch++;	
			output = true;
		} else {
			if(!nxt[*st-'a'])	 {
				branch++;	
				nxt[*st-'a'] = new Trie;
			}
			words++;
			nxt[*st-'a']->insert(st+1);
		}
	}

	lint keyCount(bool isRoot=false) {
		lint cnt = 0;	
		if(isRoot || branch > 1) cnt = words;
		for(int i = 0; i < 26; i++) {
			if(nxt[i]) cnt += nxt[i]->keyCount();	
		}
		return cnt;
	}
};

void solve(int n) {
	Trie *root = new Trie;
	for(int i = 0; i < n; i++) {
		char word[81];
		scanf("%s", word);
		root->insert(word);
	}
	lint res = root->keyCount(true);
	printf("%.2lf\n", 1.0*res/n);
	delete root;
}

int main() {
	int n;
	while(scanf("%d", &n) > 0) {
		solve(n);
	}
}
