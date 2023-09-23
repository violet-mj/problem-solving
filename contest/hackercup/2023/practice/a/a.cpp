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
	int s, d, k;			
	cin >> s >> d >> k;

	int kBun = k + 1;
	int kGogi = k;

	int currBun = 2 * (s + d);
	int currGogi = s + d * 2;

	cout << "Case #" << seq << ": ";
	if(currBun >= kBun && currGogi >= kGogi) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

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
