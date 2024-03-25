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

map<int, set<int>> m = {
	{1, set<int>({})},
	{2, set<int>({4, 6})},
	{3, set<int>({4, 6})},
	{4, set<int>({1, 3})},
	{5, set<int>({1, 3})},
	{6, set<int>({8})},
	{7, set<int>({8})},
	{8, set<int>({5, 7})},
};

void solve(int tn, string s) {
	if(s[0] != '1' || s[s.size() - 1] != '2') {
		cout << tn << ". NOT\n";
		return;
	}

	for(int i = 1; i < s.size(); i++)	{
		debug(s[i], s[i-1] - '0');
		int curr = s[i] - '0';
		int prev = s[i-1] - '0';
		if(m[curr].find(prev) == m[curr].end())	{
			cout << tn << ". NOT\n";
			return;
		}
	}

	cout << tn << ". VALID\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int i = 1;
	while(1) {
		string s; cin >> s;
		if(s == "0") break;
		solve(i++, s);
	}
}
