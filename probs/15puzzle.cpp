#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;
using ull = unsigned long long;
using ti = tuple<int, int, vector<int>, string>;

const int MAX = 16;
const ull ANS = 0x123456789ABCDEF0;

pair<int, char> mv[4] = { {1,'R'}, {-1,'L'}, {4,'D'}, {-4,'U'} };

ull hashBoard(vector<int> board)
{
    ull ret = 0;
    for (int i = 0; i < MAX; i++) ret |= ((ull)board[MAX-i-1] << (4*i));
    return ret;
}

int dist(int x, int y)
{
    return abs(x/4 - y/4) + abs(x%4 - y%4);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    vector<int> B(16); for (int i = 0; i < MAX; i++) cin >> B[i];

    int chk = 0;
    for (int i = 0; i < MAX; i++) {
        if (B[i] == 0) chk += i/4;
        else for (int j = i+1; j < MAX; j++) chk += B[j] ? B[i] > B[j] : 0;
    }

    cout << hex;
    if (chk%2) {
        priority_queue<ti, vector<ti>, greater<ti>> pq; pq.emplace(0, 0, B, "");
        map<ull, int> V; V[hashBoard(B)] = 0;
        while (!pq.empty()) {
            auto [weight, depth, board, ans] = pq.top(); pq.pop();

            ull h = hashBoard(board);

            // for (int i = 0; i < MAX; i++) cout << board[i] << ' '; cout << '\n';
            // cout << h << '\n';
            // cout << ANS << '\n';

            if (V[h] < depth) continue;
            if (h == ANS) {
                cout << depth << '\n';
                cout << ans << '\n';
                break;
            }

            for (int i = 0; i < MAX; i++) {
                if (!board[i]) {
                    for (auto [di, dir] : mv) {
                        int ni = i+di;
                        if (in(ni, 0, MAX) && (i/4 == ni/4 || i%4 == ni%4)) {
                            swap(board[i], board[ni]);

                            int d = 0;
                            for (int i = 0; i < MAX; i++)
                                if (board[i]) d += dist(i+1, board[i]);

                            ull nh = hashBoard(board);
                            if (V.find(nh) == V.end() || V[nh] > depth+1) {
                                V[nh] = depth+1;
                                pq.emplace(d+depth+1, depth+1, vector<int>(board), ans+dir);
                            }

                            swap(board[i], board[ni]);
                        }
                    }
                }
            }
        }
    }
    else cout << "Unsolvable\n";

    return 0;
}
