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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

int gcd(int a, int b) {
	while(b != 0) {
		a = a % b;	
		swap(a, b);
	}
	return a;
}

// 정수가 int형의 범위를 넘어가는지
// integer overflow 확인
// 정방향이 아닌 역방향도 생각해보기
void solve() {
	int n, p;
	cin >> n >> p;

	vector<int> v1(n, 0);
	vector<int> v2(n, 0);
	vector<int> v11;
	vector<int> v22;

	for(int i = 0; i < n; i++) cin >> v1[i];
	for(int i = 0; i < n; i++) cin >> v2[i];

	int g1 = v1[0];
	int g2 = v2[0];

	for(int i= 0 ; i < n; i++) {
		g1 = gcd(g1, v1[i]);
		g2 = gcd(g2, v2[i]);
	}
	lint sum1 = 0;
	lint sum2 = 0;
	for(int i = 0; i < n; i++) {
		v11.pb(v1[i] / g1);
		v22.pb(v2[i] / g2);
		sum1 += (lint)v11[i];
		sum2 += (lint)v22[i];
	}

	lint m = 1;	
	for(int i = 0; i < n; i++) {

		lint l = 0;
		lint r = 1000000000;
		
		while(l + 1 < r) {
			lint mid = (l + r) >> 1;	
			if(v22[i] * mid < v11[i]) {
				l = mid;	
			} else{ 
				r = mid;	
			}
		}

		m = max(m, r);
	}

	cout << sum1 << " " << sum2 * m << "\n";


}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
