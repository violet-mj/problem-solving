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
	string s;		
	cin >> s;

	if(s == "tourist") {
		cout << 3858 << "\n";
	} else if(s == "ksun48") {
		cout <<  3679 << "\n";
	} else if(s == "Benq") {
		cout <<  3658 << "\n";
	} else if(s == "Um_nik") {
		cout <<  3648 << "\n";
	} else if(s == "apiad") {
		cout <<  3638 << "\n";
	} else if(s == "Stonefeang") {
		cout <<  3630 << "\n";
	} else if (s == "ecnerwala") {
		cout << 3613 << "\n";
	} else if (s == "mnbvmar") {
		cout << 3555 << "\n";
	} else if (s == "newbiedmy") {
		cout << 3516 << "\n";
	} else {
		cout << 3481 << "\n";
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
