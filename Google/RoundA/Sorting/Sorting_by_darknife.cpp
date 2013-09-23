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


int a[1005], n;

vector<int> A, B;
bool v[1005];


int main() {
	int Te;
	scanf("%d", &Te);
	for (int Ti = 1; Ti <= Te; Ti++) {
		scanf("%d", &n);
		A.clear(), B.clear();
		REP(i, n) {
			int x;
			scanf("%d", &x);
			if ((x + 5000) % 2 == 0)
				B.push_back(x), v[i] = true;
			else
				A.push_back(x), v[i] = false;
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		reverse(B.begin(), B.end());
		int x = 0, y = 0;
		printf("Case #%d:", Ti);
		REP(i, n) {
			int w;
			if (v[i]) w = B[y++]; else w = A[x++];
			printf(" %d", w);
		}
		puts("");
	}
}