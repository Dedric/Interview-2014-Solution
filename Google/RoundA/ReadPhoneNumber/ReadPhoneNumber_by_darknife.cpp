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


string s, t;

char num[10][100] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char cal[10][100] = {"double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};

void ma(int i, int n) {
//	cout << "WIR " << i << n << endl;
	if (n == 1 || n > 10) {
		REP(I, n) printf(" %s", num[i]);
	} else {
		printf(" %s %s", cal[n - 2], num[i]);
	}
}

void calc(string tmp) {
	//cout << "NOW " << tmp << endl;
	int n = tmp.length(), j = 0;
	REP(i, n) if (i == n - 1 || tmp[i] != tmp[i + 1]) {
		ma(tmp[i] - '0', i - j + 1);
		j = i + 1;
	}
}

int main() {
	int Te;
	scanf("%d", &Te);
	for (int Ti = 1; Ti <= Te; Ti++) {
		cin >> s >> t;
		t.push_back(' ');
		REP(i, (int) t.length()) if (t[i] == '-') t[i] = ' ';
		istringstream ssin(t);
		int x, y = 0;
		printf("Case #%d:", Ti);
		while (ssin >> x) {
	//		cout << "! " << x << endl;
			string tmp;
			REP(i, x) tmp.push_back(s[y++]);
			calc(tmp);
		}
		puts("");
	}
}