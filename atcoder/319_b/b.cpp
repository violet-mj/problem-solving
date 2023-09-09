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

const string DIGIT = "0123456789";

void solve() {
	string res = "";		
	int N;
	cin >> N;

	for(int i= 0; i <= N; i++) {
		bool flag = false;
		for(int j = 1; j <= 9; j++) {
			if(N % j != 0) continue;
			int nj = N / j;	
			if(i % nj == 0) {
				res += DIGIT[N / nj];
				flag = true;
				break;
			}
		}

		if(!flag) {
			res += '-';
		} 
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
