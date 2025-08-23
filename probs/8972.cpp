#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 100;

char A[MAX][MAX], tmp[MAX][MAX];
int mv[][2] = { {0,0}, {1,-1}, {1,0}, {1,1}, {0,-1}, {0,0}, {0,1}, {-1,-1}, {-1,0}, {-1,1} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int R, C, x, y; cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'I') x = i, y = j, A[i][j] = '.';
        }
    }

    string S; cin >> S;
    for (int i = 0; i < S.size(); i++) {
        auto [dx, dy] = mv[S[i]-'0'];
        int nx = x+dx, ny = y+dy;
        if (A[nx][ny] == 'R') {
            cout << "kraj " << i+1 << '\n';
            return 0;
        }
        else A[x][y] = '.', A[nx][ny] = 'I', x = nx, y = ny;

        fill(&tmp[0][0], &tmp[R][0], '.');
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (A[r][c] == 'R') {
                    int nr, nc;

                    if (r < x) nr = r+1;
                    else if (r > x) nr = r-1;
                    else nr = r;

                    if (c < y) nc = c+1;
                    else if (c > y) nc = c-1;
                    else nc = c;

                    if (nr == x && nc == y) {
                        cout << "kraj " << i+1 << '\n';
                        return 0;
                    }
                    else if (tmp[nr][nc] == '.') tmp[nr][nc] = 'R';
                    else tmp[nr][nc] = 'X';
                }
            }
        }

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                A[r][c] = tmp[r][c] == 'R' ? 'R' : '.';
    }

    A[x][y] = 'I';
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++)
            cout << A[r][c];
        cout << '\n';
    }

    return 0;
}
