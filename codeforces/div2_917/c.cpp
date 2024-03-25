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

void solve() {
	int n, k, d;		
	cin >> n >> k >> d;
	vector<int> ai(n);
	vector<int> bi(k);
	for(int i = 0; i < n; i++) cin >> ai[i];
	for(int i = 0; i < k; i++) cin >> bi[i];

	int find = 1;
	int gcnt = 0;


	auto check = [&]() {
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(i + 1 == ai[i])	{
				cnt++;	
			}
		}
		return cnt;
	};

	for(int i = 0; i < min(2 * n, d); i++) {
		int cv = check();	
		int result = cv + (d - i - 1) / 2;
		debug(i, result);
		gcnt = max(result, gcnt);
		int idx = i % k;
		int cb = bi[idx];
		for(int i = 0; i < cb; i++) {
			ai[i]++;	
		}
	}

	cout << gcnt << "\n" ;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
