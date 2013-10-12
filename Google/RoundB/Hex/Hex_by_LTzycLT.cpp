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

int n;
char g[200][200];
bool flag=true;
int dx[]={0,0,-1,-1,1,1},dy[]={-1,1,0,1,0,-1};
int s,t,a,b,sa,sb,id[200][200];
int vis[200000];
vector<int> e[200000];
queue<int> q;

bool bfs(int s,int t){
    while(!q.empty()) q.pop();
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int j=0;j<(int)e[u].size();j++){
            int v=e[u][j];
            if(vis[v]==-1){
                vis[v]=1;
                q.push(v);
            }
        }
    }
    if(vis[t]==1) return true;
    else return false;
}
void calc(char c,int &a){
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(g[i][j]==c)
                id[i][j]=++cnt;
    int s=0,t=cnt+1;
    for(int i=s;i<=t;i++) e[i].clear();
    if(c=='R'){
        for(int j=0;j<n;j++) if(g[0][j]==c) e[s].push_back(id[0][j]);
        for(int j=0;j<n;j++) if(g[n-1][j]==c) e[id[n-1][j]].push_back(t);
    }else{
        for(int i=0;i<n;i++) if(g[i][0]==c) e[s].push_back(id[i][0]);
        for(int i=0;i<n;i++) if(g[i][n-1]==c) e[id[i][n-1]].push_back(t);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(g[i][j]==c){
                for(int k=0;k<6;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx<0||ny<0||nx>=n||ny>=n||g[nx][ny]!=c) continue;
                    e[id[i][j]].push_back(id[nx][ny]);
                }
            }
    for(int i=s;i<=t;i++) vis[i]=-1;
    if(bfs(s,t)){
        a=2;
        for(int i=1;i<=cnt;i++){
            for(int j=s;j<=t;j++) vis[j]=-1;
            vis[i]=-2;
            if(!bfs(s,t)) a=1;
        }
    }else a=0;
}
int main() {
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        flag=true;
        scanf("%d",&n);
        a=0,b=0,sa=0,sb=0;
        for(int i=0;i<n;i++){
            scanf("%s",g[i]);
            for(int j=0;j<n;j++){
                if(g[i][j]=='R') sa++;
                if(g[i][j]=='B') sb++;
            }
        }
        calc('B',b);
        calc('R',a);

        if(abs(sa-sb)>1 || a+b>1) flag=false;
        if(a+b==1){
            if(a && sa<sb) flag=false;
            if(b && sb<sa) flag=false;
        }
        printf("Case #%d: ",++cas);
        if(!flag) printf("Impossible\n");
        else{
            if(a==1) printf("Red wins\n");
            else if(b==1) printf("Blue wins\n");
            else printf("Nobody wins\n");
        }
    }
    return 0;
}
