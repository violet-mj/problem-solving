
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

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
double a, b;
void solve() {
	scanf("%lf %lf", &a, &b);
	double c = b / a;
	printf("%.3lf\n", c);
}

int main() {
	solve();
}
