#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
const int N = 101;
int map[N][N];
pair<int, int> dis[N][N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int sx, sy, ex, ey;
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &map[i][j]);
				dis[i][j] = make_pair(INT_MAX, INT_MIN);
			}
		}
		queue<pair<int, int> > q;
		q.push(make_pair(sx, sy));
		dis[sx][sy] = make_pair(0, map[sx][sy]);		
		while (q.size()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int d = 0; d < 4; ++d) {
				int tx = x + dx[d], ty = y + dy[d];	
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] != -1) {
					if (dis[tx][ty].first < dis[x][y].first + 1) {
						continue;
					}
					if (dis[tx][ty].first == INT_MAX) {
						q.push(make_pair(tx, ty));
					}
					dis[tx][ty].first = dis[x][y].first + 1;
					dis[tx][ty].second = max(dis[tx][ty].second, dis[x][y].second + map[tx][ty]);
				}
			}
		}
		static int id = 0;
		printf("Case #%d: ", ++id);
		if (dis[ex][ey].first == INT_MAX) {
			printf("Mission Impossible.\n");
		} else {
			printf("%d\n", dis[ex][ey].second);
		}
	}
	return 0;
}
