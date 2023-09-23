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

void solve(int seq) {
	lint A, B, C;
	cin >> A >> B >> C;
	lint Bun=0;
	lint Cheeze=0;
	if(A * 2 <= B) {
		lint count = C/A;
		Bun += 2 * count;
		Cheeze += count;
		C -= count * A;
		count = C/B;
		Bun += 2 * count;
		Cheeze += 2 * count;
	} else {
		lint count = (lint)C / B;
		Bun += 2 * count;
		Cheeze += count * 2;
		C -= count * B;
		count = C/A;
		Bun += 2 * count;
		Cheeze += count;
	}

	cout << "Case #" << seq << ": " << min(Bun == 0 ? 0 : Bun-1, Cheeze) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve(i+1);
}
