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

vector<int> v;
vector<int> preSum;

int digitSum(int target) {
	int cnt = 0;
	while(target != 0) {
		cnt += target % 10;	
		target /= 10;
	}
	return cnt;
}

void preCal() {
	v.resize(200001, 0); preSum.resize(200001, 0);
	for(int i = 1; i <= 200000; i++) {
		v[i] = digitSum(i);
	}

	for(int i = 1; i <= 200000; i++) {
		preSum[i] = preSum[i-1] + v[i];
	}
}


void solve() {
	int n; cin >> n;
	cout << preSum[n] << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	preCal();
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
