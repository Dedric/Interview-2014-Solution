#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <algorithm>
#define forn(i,n) for(int i=0;i<n;i++)
#define clr(a,b) memset(a,b,sizeof(a))
#define ll long long
#define Min(a,b) if(a>b)a=b
#define MP(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
using namespace std;

const int N=1000005;
int B,n;
int x[N],y[N];
struct point{
    int x,y;
}a[N];
map<ll,pair<ll,ll> > zycx,zycy;
ll sx[N],sy[N];


int main() {
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--){
        scanf("%d",&B);
        n=0;
        for(int i=1;i<=B;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int j=x1;j<=x2;j++){
                for(int k=y1;k<=y2;k++){
                    x[++n]=j;
                    y[n]=k;
                    a[n].x=j;
                    a[n].y=k;
                }
            }
        }
        zycx.clear();
        zycy.clear();
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        for(int i=1;i<=n;i++){
            sx[i]=sx[i-1]+x[i];
            sy[i]=sy[i-1]+y[i];
            zycx[x[i]]=MP(sx[i],i);
            zycy[y[i]]=MP(sy[i],i);
        }
        ll ans=1e18,p,q;
        for(int i=1;i<=n;i++){
            ll tmp=0;
            ll num=zycx[a[i].x].second,sum=zycx[a[i].x].first;
            tmp += num*a[i].x+(n-num)*(-a[i].x)-sum+(sx[n]-sum);

            num=zycy[a[i].y].second,sum=zycy[a[i].y].first;
            tmp += num*a[i].y+(n-num)*(-a[i].y)-sum+(sy[n]-sum);
            bool flag=false;
            if(tmp<ans){
                flag=true;
            }else if(tmp==ans){
                if(a[i].x<p){
                    flag=true;
                }else if(a[i].x==p){
                    if(a[i].y<q)
                        flag=true;
                }
            }
            if(flag){
                ans=tmp;
                p=a[i].x;
                q=a[i].y;
            }
        }
        printf("Case #%d: %lld %lld %lld\n",++cas,p,q,ans);
    }

    return 0;
}
