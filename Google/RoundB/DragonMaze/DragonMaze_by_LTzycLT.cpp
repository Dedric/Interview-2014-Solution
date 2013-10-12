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

const int inf=1e8;
int n,m;
int sx,sy,ex,ey;
int g[200][200];
int d[200][200],p[200][200];
queue<int> q;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int bfs(){
    while(!q.empty()) q.pop();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            d[i][j]=inf;
            p[i][j]=0;
        }
    q.push(sx);q.push(sy);
    p[sx][sy]=g[sx][sy];
    d[sx][sy]=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(x<0||x>=n||y<0||y>=m||g[x][y]==-1) continue;
            if(d[x][y]+1<d[nx][ny]){
                d[nx][ny]=d[x][y]+1;
                p[nx][ny]=p[x][y]+g[nx][ny];
                q.push(nx);
                q.push(ny);
            }else if(d[x][y]+1==d[nx][ny]){
                int tmp=p[x][y]+g[nx][ny];
                if(tmp>p[nx][ny])
                    p[nx][ny]=tmp;
            }
        }
    }
    if(d[ex][ey]==inf) return -1;
    else return p[ex][ey];
}
int main() {
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&g[i][j]);
        int ans=bfs();
        printf("Case #%d: ",++cas);
        if(ans!=-1) printf("%d\n",ans);
        else printf("Mission Impossible.\n");
    }
    return 0;
}
