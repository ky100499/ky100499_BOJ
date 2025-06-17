#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x <= b)

using namespace std;

char A[100][100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    vector<tuple<string, int, int>> W;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '+') {
                int x = i+1, y = j+1;
                string t;
                while (A[i][y] != '+') {
                    if (in(A[i][y], 'a', 'z')) t += A[i][y];
                    y++;
                }
                while (A[x][j] != '+') x++;
                A[i][y] = A[x][j] = A[x][y] = '.';

                W.emplace_back(t, x-i+1, y-j+1);
            }
        }
    }
    sort(W.begin(), W.end());

    fill(&A[0][0], &A[N][0], '.');
    for (int i = 0; i < W.size(); i++) {
        auto [t, h, w] = W[i];
        int d = w - t.size() - 4;
        string s = '+' + string(d/2, '-') + '|' + t + '|' + string((d+1)/2, '-') + '+';
        for (int j = 0; j < w; j++) A[i][i+j] = s[j];

        s = '|' + string(w-2, '.') + '|';
        for (int j = 1; j < h-1; j++)
            for (int k = 0; k < w; k++)
                A[i+j][i+k] = s[k];

        s = '+' + string(w-2, '-') + '+';
        for (int j = 0; j < w; j++)
            A[i+h-1][i+j] = s[j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << A[i][j];
        cout << '\n';
    }

    return 0;
}
