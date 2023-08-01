#include <iostream>
using namespace std;
using ll = long long;

long n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	ll md = m / 4;
	ll mr = m % 4;
	ll end = 0;
	for(ll i = md * 4; i < md*4 + mr + 1; i++) {
		end ^= i;
	}
	
	ll n1d = (n-1) / 4;
	ll n1r = (n-1) % 4;
	ll start = 0;
	for(ll i = n1d * 4; i < n1d*4 + n1r + 1; i++) {
		start ^= i;
	}
	
	cout << (end ^ start) << "\n";

	return 0;
}
