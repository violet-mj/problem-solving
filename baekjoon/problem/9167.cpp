#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <sstream>
#include <cctype>

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

vector<string> prt;
int taunts;
bool isFirst;
map<string, int> cnt;
map<string, int> curr;
map<string, vector<vector<string>>> m = {
	{"taunt", {{"sentence"}, {"taunt", "sentence"}, {"noun", "!"}, {"sentence"}}},
	{"sentence", {{"past-rel", "noun-phrase"}, {"present-rel", "noun-phrase"}, {"past-rel", "article", "noun"}}},
	{"noun-phrase", {{"article", "modified-noun"}}},
	{"modified-noun", {{"noun"}, {"modifier", "noun"}}},
	{"modifier", {{"adjective"}, {"adverb", "adjective"}}},
	{"present-rel", {{"your", "present-person", "present-verb"}}},
	{"past-rel", {{"your", "past-person", "past-verb"}}},
	{"present-person", {{"steed"}, {"king"}, {"first-born"}}},
	{"past-person", {{"mother"}, {"father"}, {"grandmother"}, {"grandfather"}, {"godfather"}}},
	{"noun", {{"hamster"}, {"coconut"}, {"duck"}, {"herring"}, {"newt"}, {"peril"}, {"chicken"}, {"vole"}, {"parrot"}, {"mouse"}, {"twit"}}},
	{"present-verb", {{"is"}, {"masquerades as"}}},
	{"past-verb", {{"was"}, {"personified"}}},
	{"article", {{"a"}}},
	{"adjective", {{"silly"}, {"wicked"}, {"sordid"}, {"naughty"}, {"repulsive"}, {"malodorous"}, {"ill-tempered"}}},
	{"adverb", {{"conspicuously"}, {"categorically"}, {"positively"}, {"cruelly"}, {"incontrovertibly"}}}
};

set<string> checkNoun;

void recur(string currStr) {
	debug(currStr, isFirst);
	if(currStr == "taunt") {
		taunts--;
	}
	if(m.find(currStr) == m.end()) {

		if(isFirst) {
			currStr[0] -= 32;	
			isFirst = false;
		}

		if(currStr == "!") {
			isFirst = true;	
		} else {
			cout << " ";
		}
		cout << currStr;
	} else {
		curr[currStr] %= cnt[currStr];
		vector<string> currVec = m[currStr][curr[currStr]++];
		for(string nextStr: currVec) {
			recur(nextStr);
		}
	}
}

bool isAlphaExist(string s) {
	for(char c: s) {
		if(isalpha(c)) return true;
	}
	return false;
}

void solve(string inp) {
	vector<string> strs;
	string total = "";
	stringstream ss(inp);


	string tmp;
	int notValidStr = 0;
	while(ss >> tmp) {
		strs.pb(tmp);
		total += tmp;
		if(!isAlphaExist(tmp)) notValidStr++;
	}

	taunts = (strs.size() + 2 - notValidStr) / 3;

	cout << "Knight: ";

	for(string kni: strs) {
		cout << kni << " ";
	}
	cout << "\n";

	string THG = "theholygrail";
	int thg = 0;

	for(int i = 0; i < total.size(); i++) {
		if(THG[thg] == total[i]) thg++;
		if(thg >= 12) break;
	}

	if(thg == 12) {
		cout << "Taunter: (A childish hand gesture).\n";
		taunts--;
	}

	 while(taunts > 0) {
		isFirst = true;
	 	curr["taunt"] %= cnt["taunt"];
	 	cout << "Taunter:";
		taunts--;
	 	vector<string> tmps = m["taunt"][curr["taunt"]++];
	 	for(string tmp: tmps) {
	 		recur(tmp);
	 	}
		cout << ".\n";
	 }
	 cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	for(auto i: m) {
		cnt[i.f] = i.s.size();
		curr[i.f] = 0;
	}

	for(auto v: m["noun"]) {
		checkNoun.insert(v[0]);
	}
	debug(checkNoun);
	string s;
	while(getline(cin, s)) {
		if(s.size() == 0) break;
		solve(s);
	}
}
