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

const int INF = (1 << 30) + 1;

void solve() {
	int n;	
	cin >> n;
	vector<int> values(n);
	int minv = INF;
	int idx = -1;
	for(int i = 0; i < n; i++) {
		cin >> values[i];
		if(values[i] < minv) {
			minv = values[i];
			idx = i;
		}
	}
	int check;	
	for(int i = idx + 1; i < n; i++) {
		if(i == idx + 1)	 {
			check = values[i];
		} else {
			if(values[i] < check)	{
				cout <<	"-1\n";
				return;
			} else {
				check = values[i];
			}
		}
	}
	cout << idx << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
