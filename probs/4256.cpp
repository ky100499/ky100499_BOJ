#include <bits/stdc++.h>

using namespace std;

vector<int> po, io, io_idx;

void postord(int ps, int pe, int is, int ie)
{
    if (ps > pe) return;

    int root = po[ps], root_idx = io_idx[root];
    postord(ps+1, ps+root_idx-is, is, root_idx-1);
    postord(ps+root_idx-is+1, pe, root_idx+1, ie);
    cout << root << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        po.resize(N); io.resize(N); io_idx.resize(N+1);
        for (int i = 0; i < N; i++) {
            cin >> po[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> io[i];
            io_idx[io[i]] = i;
        }
        postord(0, N-1, 0, N-1);
        cout << '\n';
    }

    return 0;
}
