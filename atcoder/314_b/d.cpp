#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

int n, q, ti, xi;
char ci;
string s;

void solve() {
	cin >> n >> s;
	char sc[n];
	bitset<500000> bits;

	for(int i = 0; i < n; i++) {
		sc[i] = s[i];
		if(isupper(s[i])) {
			bits.set(i);	
		} else {
			bits.reset(i);
		}
	}

	cin >> q;

	for(int i = 0; i < q; i++) {
		cin >> ti >> xi >> ci;	
		if(ti == 1) {
			sc[xi-1] = ci;
			if(isupper(ci)) {
				bits.set(xi-1);	
			} else {
				bits.reset(xi-1);
			}	
		} else if (ti == 2) {
			bits.reset();
		} else {
			bits.set();
		}
	}

	char res;

	for(int i = 0; i < n; i++) {
		if( bits[i]	== 1 ) {
			res = toupper(sc[i]); 
		} else {
			res = tolower(sc[i]);
		}
		cout << res;
	}

	cout <<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
