#include <iostream>
#include <vector>

using namespace std;

vector<int> ST;

void update(int i, int l, int h, int k, int v)
{
    if (l == h) {
        ST[i] = v;
    }
    else {
        int m = (l+h) / 2;
        if (k <= m) update(2*i, l, m, k, v);
        else update(2*i+1, m+1, h, k, v);
        ST[i] = max(ST[2*i], ST[2*i+1]);
    }
}

int find(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e) {
        return ST[i];
    }
    else if (e < l || h < s) {
        return 0;
    }
    else {
        int m = (l+h) / 2;
        return max(
            find(2*i, l, m, s, e),
            find(2*i+1, m+1, h, s, e)
        );
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        ST.clear(); ST.resize(4*N);
        vector<pair<int, int>> minmax(N+1, {N, -1});
        for (int i = 0; i < N; i++) {
            int ipt; cin >> ipt;
            minmax[ipt] = {
                min(minmax[ipt].first, i),
                max(minmax[ipt].second, i)
            };
            update(1, 0, N-1, i, ipt);
        }

        int ans = 1;
        for (int i = 1; i <= N && ans; i++) {
            if (minmax[i].first < N) {
                ans = ans && find(1, 0, N-1, minmax[i].first, minmax[i].second) <= i;
            }
        }
        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}
