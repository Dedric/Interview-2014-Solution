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
char s[10000000];
bool vis[10000000];

bool isl(int i){
    if(s[i]=='/' && s[i+1]=='*') return true;
    else return false;
}
bool isr(int i){
    if(s[i]=='*' && s[i+1]=='/') return true;
    else return false;
}
int main() {
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
    while(gets(s+n)){
        n+=strlen(s+n);
        s[n]='\n';
        n++;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(i+1<n && isl(i)){
            vis[i]=1;
            vis[i+1]=1;
            i++;
            cnt++;
        }
        else if(cnt>0 && i+1<n && isr(i)){
            vis[i]=1;
            vis[i+1]=1;
            i++;
            cnt--;
        }
        else if(cnt>0) vis[i]=1;
    }
    printf("Case #1:\n");
    int pre=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            printf("%c",s[i]);
            pre=s[i];
        }
    }
    return 0;
}
