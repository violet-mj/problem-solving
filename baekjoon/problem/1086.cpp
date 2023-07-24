#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <numeric>

using namespace std;

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

vector<string> v1;
vector<int> v;
int n, k;
string tmp;
long dp[1 << 15][100];
int digit[15];
int re10[1001];

int bitCheck(int num) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if(num & (1 << (n - i - 1))) {
			cnt += digit[i];	
		}
	}
	return cnt;
}

long gcd (long a, long b) {
	if(!b) return a;
	return gcd(b, a%b);
}



void solve() {
	cin >> n;
	fill(&dp[0][0], &dp[32767][100], 0);
	for(int i = 0; i < n; i++) {
		cin >> tmp;	
		v1.pb(tmp);
	}
	cin >> k;


	for(int i = 0; i < n; i++) {
		digit[i] = v1[i].length();
	}	


	re10[0] = 1;
	for(int i = 1; i < 1000; i++ ){
		re10[i] = re10[i-1] * 10 % k;
	}

	for(int i = 0; i < n; i++) {
		string curr_ = v1[i];
		int remainder = 0;	
		int cd = 0;
		for(int j = curr_.length() - 1; j >= 0; j--){
			int d = curr_.at(j) - '0';
			remainder = (remainder % k +  d * re10[cd] % k) % k;
			cd++;
		}
		v.pb(remainder);
	}

	if(debug) {
	//		for(int i = 0; i < 50; i++) {
	//		cout << re10[i] << " ";		
	//	}
	//	cout << "\n";
	}

	for(int i = 0; i < n; i++) {
		int remain = v[i];
		dp[1 << (n - i - 1)][remain] += 1;
	}
	

	for(int i = 1; i < n ; i++ ) {
		for(int j = 0; j < (1 << n); j++) {
			for(int re = 0; re < k; re++) {
			  int bitCount = __builtin_popcount(j);
				if(dp[j][re] == 0) continue;
			  if(i != bitCount) continue;
			  int currR = bitCheck(j);
			  for(int z = 0; z < n; z++) {
					if(j & (1 << (n - z - 1))) continue;
				  int remain = (v[z] * re10[currR] % k + re % k) % k;
					dp[j | (1 << (n - z - 1))][remain] += dp[j][re];
			  }
			}
		}	
	}
	
	long entire = 1;

	for(int i = 1; i <= n; i++) entire *= i;
	
	long count = dp[(1 << n) - 1][0];

	auto g = gcd(entire, count);
	if(debug) cout << "g : " << g << "\n";
	if(count != 0 && g != 0) {
		entire /= g;
		count /= g;
	} else {
		entire = 1;	
	}

	cout << count << "/" << entire<< "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
