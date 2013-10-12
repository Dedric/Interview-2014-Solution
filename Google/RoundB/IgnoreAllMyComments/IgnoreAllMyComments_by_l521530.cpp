// TwT514 {{{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

char c[1001001];
int lv=0;
void solve(){
	puts("Case #1:");
	while(gets(c)){
		int l = strlen(c);
		for(int i=0;i<l;){
			if(c[i]=='/' && c[i+1]=='*'){
				i+=2;
				lv++;
			}
			else if(c[i]=='*' && c[i+1]=='/'){
				if(lv==0){
					putchar(c[i]);
					i++;
				}
				else{
					lv--;
					i+=2;
				}
			}
			else{
				if(lv==0) putchar(c[i]);	
				i++;
			}
		}
		if(lv==0)puts("");
	}
}

int main() {
	solve();
	return 0;
}


