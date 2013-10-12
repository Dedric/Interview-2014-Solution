#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};

int T, n, m, enx, eny, exx, exy;
int a[100][100];
int d[100][100];
int dp[100][100];

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%d%d", &n, &m);
        scanf("%d%d%d%d", &enx, &eny, &exx, &exy);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(d, -1, sizeof(d));
        dp[enx][eny] = a[enx][eny];
        d[enx][eny] = 0;
        queue<int> q;
        q.push(enx * m + eny);
        while (!q.empty()) {
            int cx = q.front() / m;
            int cy = q.front() % m;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cx + DX[i];
                int ny = cy + DY[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != -1) {
                    if (d[nx][ny] == -1) {
                        dp[nx][ny] = max(dp[nx][ny], dp[cx][cy] + a[nx][ny]);
                        d[nx][ny] = d[cx][cy] + 1;
                        q.push(nx * m + ny);
                    } else if (d[nx][ny] == d[cx][cy] + 1) {
                        dp[nx][ny] = max(dp[nx][ny], dp[cx][cy] + a[nx][ny]);
                    }
                }
            }
        }
        if (dp[exx][exy] == -1) {
            printf("Case #%d: Mission Impossible.\n", caseNum);
        } else {
            printf("Case #%d: %d\n", caseNum, dp[exx][exy]);
        }
    }
    return 0;
}
