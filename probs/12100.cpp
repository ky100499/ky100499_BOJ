#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAX = 20;

int N, ans = 0, pos;

void bt(int n, vvi B)
{
    if (n == 5) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans = max(ans, B[i][j]);
    }
    else {
        // left
        vvi board(N, vi(N));
        for (int i = 0; i < N; i++) {
            pos = 0;
            for (int j = 0; j < N; j++) {
                if (B[i][j]) board[i][pos++] = B[i][j];
            }

            pos = 0;
            for (int j = 0; j < N; j++) {
                if (board[i][j] && j+1 < N && board[i][j] == board[i][j+1]) {
                    int s = board[i][j]+board[i][j+1];
                    board[i][j] = board[i][j+1] = 0;
                    board[i][pos++] = s;
                    j++;
                }
                else if (board[i][j]) {
                    int s = board[i][j];
                    board[i][j] = 0;
                    board[i][pos++] = s;
                }
            }
        }
        bt(n+1, board);

        // right
        board = vvi(N, vi(N));
        for (int i = 0; i < N; i++) {
            pos = N-1;
            for (int j = N-1; j >= 0; j--) {
                if (B[i][j]) board[i][pos--] = B[i][j];
            }

            pos = N-1;
            for (int j = N-1; j >= 0; j--) {
                if (board[i][j] && j-1 >= 0 && board[i][j] == board[i][j-1]) {
                    int s = board[i][j]+board[i][j-1];
                    board[i][j] = board[i][j-1] = 0;
                    board[i][pos--] = s;
                    j--;
                }
                else if (board[i][j]) {
                    int s = board[i][j];
                    board[i][j] = 0;
                    board[i][pos--] = s;
                }
            }
        }
        bt(n+1, board);

        // up
        board = vvi(N, vi(N));
        for (int j = 0; j < N; j++) {
            pos = 0;
            for (int i = 0; i < N; i++) {
                if (B[i][j]) board[pos++][j] = B[i][j];
            }

            pos = 0;
            for (int i = 0; i < N; i++) {
                if (board[i][j] && i+1 < N && board[i][j] == board[i+1][j]) {
                    int s = board[i][j]+board[i+1][j];
                    board[i][j] = board[i+1][j] = 0;
                    board[pos++][j] = s;
                    i++;
                }
                else if (board[i][j]) {
                    int s = board[i][j];
                    board[i][j] = 0;
                    board[pos++][j] = s;
                }
            }
        }
        bt(n+1, board);

        // down
        board = vvi(N, vi(N));
        for (int j = 0; j < N; j++) {
            pos = N-1;
            for (int i = N-1; i >= 0; i--) {
                if (B[i][j]) board[pos--][j] = B[i][j];
            }

            pos = N-1;
            for (int i = N-1; i >= 0; i--) {
                if (board[i][j] && i-1 >= 0 && board[i][j] == board[i-1][j]) {
                    int s = board[i][j]+board[i-1][j];
                    board[i][j] = board[i-1][j] = 0;
                    board[pos--][j] = s;
                    i--;
                }
                else if (board[i][j]) {
                    int s = board[i][j];
                    board[i][j] = 0;
                    board[pos--][j] = s;
                }
            }
        }
        bt(n+1, board);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    vvi B(N, vi(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    bt(0, B);
    cout << ans << '\n';

    return 0;
}
