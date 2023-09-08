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

int N, U, L;

void solve() {
	cin >> N >> U >> L;	

	bool f1 = false;
	bool f2 = false;

	if(N >= 1000) {
		f1 = true;	
	}

	if(U >= 8000 || L >= 260) {
		f2 = true;	
	}

	if(f1 && f2) {
		cout << "Very Good\n";
	} else if(f1) {
		cout << "Good\n";
	} else {
		cout << "Bad\n";
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
