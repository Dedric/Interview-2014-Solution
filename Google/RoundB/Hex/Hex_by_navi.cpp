#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int DX[] = {-1, -1, 0, 0, 1, 1};
const int DY[] = {0, 1, -1, 1, -1, 0};
const char* ANS[] = {"Impossible", "Red wins", "Blue wins", "Nobody wins"};

// Maxflow Sap algorithm

#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
const int MAXM = 200005;
const int INF = 0x3f3f3f3f;

struct Sap {
#define RE(i) ((((i) - P) ^ 1) + P)
    struct Edge {
        int v, c;
        Edge* next;
        Edge(int v = 0, int c = 0, Edge* next = NULL) : v(v), c(c), next(next) {}
    };

    int n, S, T, psize, len;
    int maxflow;
    int c[MAXN];
    int d[MAXN];
    int path[MAXN];
    Edge* curr[MAXN];
    Edge P[MAXM * 2];
    Edge* e[MAXN];

    void bfs() {
        queue<int> q;
        fill(d, d + n, n);
        fill(c, c + n, 0);
        q.push(T);
        d[T] = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            ++c[d[top]];
            for (Edge* i = e[top]; i != NULL; i = i->next) {
                if (d[i->v] == n) {
                    d[i->v] = d[top] + 1;
                    q.push(i->v);
                }
            }
        }
    }

    int flow(int _S, int _T) {
        n = max(n, max(S = _S, T = _T)) + 1;
        bfs();
        for (int i = 0; i < n; ++i) {
            curr[i] = e[i];
        }
        path[maxflow = len = 0] = S;
        while (d[S] != n) {
            int u = path[len];
            if (u == T) {
                int minf = INF;
                int last = -1;
                for (int i = 0; i < len; ++i) {
                    if (curr[path[i]]->c < minf) {
                        minf = curr[path[i]]->c;
                        last = i;
                    }
                }
                for (int i = 0; i < len; ++i) {
                    curr[path[i]]->c -= minf;
                    RE(curr[path[i]])->c += minf;
                }
                len = last;
                maxflow += minf;
            } else {
                for (; curr[u] != NULL && (d[curr[u]->v] != d[u] - 1 || curr[u]->c == 0); curr[u] = curr[u]->next);
                if (curr[u] == NULL) {
                    if (--c[d[u]] == 0) {
                        break;
                    } else {
                        d[u] = n;
                        for (Edge* i = e[u]; i != NULL; i = i->next) {
                            if (d[i->v] + 1 < d[u] && i->c != 0) {
                                d[u] = d[i->v] + 1;
                                curr[u] = i;
                            }
                        }
                        ++c[d[u]];
                        (u != S) && (len--);
                    }
                } else {
                    path[++len] = curr[u]->v;
                }
            }
        }
        return maxflow;
    }

    void init() {
        n = psize = 0;
        memset(e, 0, sizeof(e));
    }

    void addEdge(int u, int v, int c) {
        P[psize] = Edge(v, c, e[u]);
        e[u] = &P[psize++];
        P[psize] = Edge(u, 0, e[v]);
        e[v] = &P[psize++];
        n = max(n, max(u, v));
    }

    void addUEdge(int u, int v, int c) {
        P[psize] = Edge(v, c, e[u]);
        e[u] = &P[psize++];
        P[psize] = Edge(u, c, e[v]);
        e[v] = &P[psize++];
        n = max(n, max(u, v));
    }
} sap;

int T, N, n;
char s[100][101];
bool visited[100][100];

int gao(char c) {
    sap.init();
    int S = 2 * n * n, T = S + 1;
    for (int i = 0; i < n; ++i) {
        if (s[0][i] == c) {
            sap.addEdge(S, i, 1);
        }
        if (s[n - 1][i] == c) {
            sap.addEdge(N + (n - 1) * n + i, T, 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == c) {
                int id = i * n + j;
                sap.addEdge(id, N + id, 1);
                for (int k = 0; k < 6; ++k) {
                    int nx = i + DX[k];
                    int ny = j + DY[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && s[nx][ny] == c) {
                        sap.addEdge(N + id, nx * n + ny, 1);
                    }
                }
            }
        }
    }

    return sap.flow(S, T);
}

int gao() {
    int blueCount = 0;
    int redCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'B') {
                ++blueCount;
            } else if (s[i][j] == 'R') {
                ++redCount;
            }
        }
    }

    if (!(blueCount <= redCount + 1 && redCount <= blueCount + 1)) {
        return 0; // impossible
    }

    int rc = gao('R');
    if (rc == 1) {
        if (redCount >= blueCount) {
            return 1; // red wins
        } else {
            return 0; // impossible
        }
    } else if (rc > 1) {
        return 0; // impossible
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(s[i][j], s[j][i]);
        }
    }

    rc = gao('B');
    if (rc == 1) {
        if (blueCount >= redCount) {
            return 2; // red wins
        } else {
            return 0; // impossible
        }
    } else if (rc > 1) {
        return 0; // impossible
    }

    return 3; // nobody wins
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%d", &n);
        N = n * n;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
        }
        printf("Case #%d: %s\n", caseNum, ANS[gao()]);
    }
    return 0;
}
