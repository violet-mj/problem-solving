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


// 정수가 int형의 범위를 넘어가는지
// integer overflow 확인
// 정방향이 아닌 역방향도 생각해보기
void solve() {
	vector<string> score;			
	string s;
	cin >> s;
	ld res = 0;
	int count = 0;
	map<char, ld> m = {
		{'A', 4.0},
		{'B', 3.0},
		{'C', 2.0},
		{'D', 1.0},
		{'F', 0.0},
	};
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '+')  {
			res += 0.5;	
		} else {
			res += m[s[i]];
			count++;
		}
	}
	debug(res);
	debug(count);

	cout << res / (ld)count << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
