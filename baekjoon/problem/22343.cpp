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

const int INF = 1500002;
void solve() {
	string s1, s2;		
	cin >> s1 >> s2;

	auto countParen = [](string c) {
		int currMul = 0;
		vector<int> check(INF, 0);

		for(int i = 1; i < c.size(); i++)	{
			if(c[i] == '(')	currMul++;
			else {
				check[currMul]++;
				currMul--;
			}
		}

			
		for(int i = 1; i < INF; i++) {
			check[i] += (check[i - 1] / 2);
			check[i - 1] = check[i - 1] % 2;
		}

		return check;
	};

	vector<int> c1 = countParen(s1);
	vector<int> c2 = countParen(s2);

	for(int i = 0; i < 10 ; i++) {
		cout << c1[i] << " ";	
	}
	cout << "\n";
	for(int i= 0; i < 10; i++) {
		cout << c2[i] << " ";	
	}
	cout << "\n";

	if(c1 == c2) {
		cout << "=";
	} else if(c1 < c2) {
		cout << "<";
	} else {
		cout << ">";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
