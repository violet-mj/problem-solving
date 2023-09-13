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
vector<int> squareCopy(10, 0);
vector<int> square;
const int fullBit = 1023;
const int sevenFullBit = 510;

int min_ = 101;
void check(int clickCount) {
	int cnt = clickCount;
	for(int i = 1; i < 10; i++) {
		for(int j = 0; j < 10; j++)	 {
			int jBit = 1 << (9 - j);
			if((square[i-1] & jBit) == 0) continue;
			square[i-1] ^= jBit;
			if(i != 9) square[i+1] ^= jBit;
			square[i] ^= (7 << (9 - j) >> 1) & fullBit;
			cnt++;
		}

		if(square[9] == 0) {
			min_ = min(cnt, min_);
		}
	}
}

void solve() {
	char s;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cin >> s;	
			if(s == 'O') {
				squareCopy[i] |= (1 << (9 - j));
			}
		}
	}

	debug(squareCopy);
	for(int i = 0; i <= 1023; i++) {
		square = squareCopy;
		int clickCount = __builtin_popcount(i);
		int firstInversion = 0;
		for(int j = 0; j < 10; j++) {
			if((i & (1 << j)) > 0)	{
				firstInversion ^= (((7 << j) >> 1) & fullBit);
			}
		}
		square[0] ^= firstInversion;
		square[1] ^= i;
		check(clickCount);
	}
	if(min_ == 101) {		
		cout << -1 << "\n";
	} else {
		cout << min_ << "\n";
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
