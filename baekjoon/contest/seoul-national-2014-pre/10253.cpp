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


struct fraction
{
    int nume;
    int deno;
    fraction(int nn, int dd) : nume(nn), deno(dd) {}
    fraction() {}
};

vector<fraction> lastFrac;

int gcd(int a, int b)
{
	while(b != 0) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

fraction sub(fraction f1, fraction f2)
{
    lint glcm = (lint)f1.deno * (lint)f2.deno / gcd(f1.deno, f2.deno);
    lint f1Nume = (lint)f1.nume * glcm / f1.deno;
    lint f2Nume = (lint)f2.nume * glcm / f2.deno;

    lint diff = abs(f1Nume - f2Nume);

    lint dGcd = gcd(diff, glcm);

    fraction res;

    res.nume = diff / dGcd;
    res.deno = glcm / dGcd;

    return res;
}

bool cmp(fraction f1, fraction f2)
{
		debug(f1.nume * f2.deno);
		debug(f1.deno * f2.nume);
    return (lint)f1.nume * f2.deno <= (lint)f1.deno * f2.nume;
}


void solve()
{
    fraction frac;
    cin >> frac.nume >> frac.deno;
	
    vector<int> fracs;
		int l, r, mid;

		int g = gcd(frac.nume, frac.deno);

		if(g != 1) {
			frac.nume /= g;	
			frac.deno /= g;	
		}
		while(frac.nume != 0) {
			l = 1;
			r = 10000;
			debug(frac.nume, frac.deno);
			while(l + 1 < r) {
				mid = (l + r) >> 1;	
				if(l < 0 || r < 0) break;
				if(cmp(lastFrac[mid], frac)) {
					r = mid;
				} else {
					l = mid;	
				}
			}
			fracs.pb(r);
			frac = sub(frac, lastFrac[r]);
    }

		cout << fracs[fracs.size()-1]<< "\n";
}


int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	lastFrac.resize(10001);
	for(int i = 2; i <= 10000; i++) {
		lastFrac[i] = fraction(1, i);
	}
	for(int i = 0; i < t; i++) solve();
}
