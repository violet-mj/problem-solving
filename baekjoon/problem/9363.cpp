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

void solve(int tn) {
	int n, m;	
	cin >> n >> m;

	vector<int> A(n, 0);
	vector<int> B(m, 0);
	vector<int> cA(1000000, 0);
	vector<int> cB(1000000, 0);

	auto facto = [](int num, vector<int>& cc) {
		int tmp = num;
		for(int i = 2; i <= sqrt(num) + 1; i++)	 {
			while(tmp % i == 0)	{
				cc[i]++;	
				tmp /= i;
			}
		}
		if(tmp != 1) cc[tmp]++;
	};


	for(int i = 0; i < n; i++) {
		cin >> A[i];
		facto(A[i], cA);
	}
	for(int i = 0; i < m; i++) {
		cin >> B[i];
		facto(B[i], cB);
	}


	for(int i = 2; i < 1000000; i++) {
		if(cA[i] > cB[i])	 {
			cA[i] -= cB[i];
			cB[i] = 0;
		} else {
			cB[i] -= cA[i];
			cA[i] = 0;
		}
	}


	lint ka = 1LL;	
	lint kb = 1LL;

	for(int i = 2; i < 1000000; i++) {
		for(int j = 0; j < cA[i]; j++) {
			ka *= i * 1LL;	
		}
		for(int j = 0; j < cB[i]; j++) {
			kb *= i * 1LL;	
		}
	}	

	cout << "Case #" << tn << ": " << ka << " / " << kb << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)  solve(i + 1);
}
