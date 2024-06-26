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

int N, T;
string tier, K;

void solve() {
	cin >> N >> T;				

	vector<string> tiers; 
	vector<int> tierCount;
	int curr = N;

	for(int i = 0; i < T; i++) {
		cin >> tier >> K;	
		int Ks = K.size();
		tiers.pb(tier);
		int Kn;
		if(K[Ks-1] == '%') {
			K = K.substr(0, Ks-1);
			Kn = stoi(K) * curr / 100;
		}	else {
			Kn = stoi(K);
		}		
		if(tierCount.size() == 0) {
			tierCount.pb(Kn);	
		} else {
			tierCount.pb(tierCount[tierCount.size() - 1] + Kn);
		}
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
