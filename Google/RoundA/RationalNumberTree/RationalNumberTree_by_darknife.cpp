#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<queue>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,n,m) for(int i = (int)n; i <= (int)m; i++)
#define FOD(i,n,m) for(int i = (int)n; i >= (int)m; i--)
#define EACH(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

typedef long long i64;
typedef pair<int, int> PI;

#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))

#define PB push_back
#define MP make_pair
#define X first
#define Y second
template<class T> void fmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void fmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> T sqr(const T &a) { return a * a; }


int a[1005];

typedef unsigned long long ull;

ull n, p, q;

int main() {
	int Te;
	scanf("%d", &Te);
	for (int Ti = 1; Ti <= Te; Ti++) {
		int x;
		cin >> x;
		if (x == 1) {
			cin >> n;
			if (n == 1) {
				cout << "Case #" << Ti << ": " << 1 << " " << 1 << endl;
				continue;
			}
			ull m = -1;
			ull nn = n;
			ull x = 1;
			while (nn != 0) {
				m++;
				nn >>= 1;
			}
			n--;
		//	cout << n << ' ' << m << endl;
			n -= x << (m - 1);
			n += 1;
			n -= x << (m - 1);
			if ((x << m) & n) ; else m--;
		//	cout << n << ' ' << m << endl;
			ull p = 1, q = 1;
			for (int i = m; i >= 0; i--) {
				if ((x << i) & n)
					p += q;
				else
					q += p;
			}
			cout << "Case #" << Ti << ": " << p << " " << q << endl;
		} else {
			cin >> p >> q;
			n = 0;
			ull x = 1;
			ull m = 0;
			while (p != 1 || q != 1) {
				if (p < q) q -= p;
				else n += x << m, p -= q;
				m++;
			}
			n += x << (m - 1);
			n -= 1;
			n += x << (m - 1);
			cout << "Case #" << Ti << ": " << n + 1 << endl;
		}
	}
}