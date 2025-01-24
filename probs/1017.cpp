#include <bits/stdc++.h>

using namespace std;

int isPrime[2000],
    V[25],
    mat[25],
    N;
vector<int> E, O;

bool match(int e)
{
    for (int i = 0; i < N/2; i++) {
        if (!isPrime[E[e]+O[i]] || V[i]) continue;
        V[i] = 1;

        if (mat[i] == -1 || match(mat[i])) {
            mat[i] = e;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    fill(isPrime, isPrime+2000, 1);
    for (int i = 2; i < 2000; i++)
        if (isPrime[i])
            for (int j = i*i; j < 2000; j += i)
                isPrime[j] = 0;

    cin >> N;
    bool change = 0;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        if (n%2) O.push_back(n);
        else E.push_back(n);

        if (i == 0) change = n%2;
    }
    if (change) swap(O, E);

    if (O.size() != N/2) cout << -1 << '\n';
    else {
        vector<int> ans;
        for (int i = 0; i < N/2; i++) {
            if (isPrime[E[0]+O[i]]) {
                memset(mat, -1, sizeof mat); mat[i] = 0;
                int cnt = 1;
                for (int j = 1; j < N/2; j++) {
                    memset(V, 0, sizeof V); V[i] = 1;
                    if (match(j)) cnt++;
                }
                if (cnt == N/2) ans.push_back(O[i]);
            }
        }

        if (ans.empty()) cout << -1 << '\n';
        else {
            sort(ans.begin(), ans.end());
            for (int a : ans) cout << a << ' '; cout << '\n';
        }
    }

    return 0;
}
