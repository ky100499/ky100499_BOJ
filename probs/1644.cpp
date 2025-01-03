#include <bits/stdc++.h>

using namespace std;

const int MAX = 4e6;

int p[MAX+1] = {};
vector<long long> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(p, p+MAX+1, 1);
    S.push_back(0);
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (p[i]) {
            for (int j = i*i; j <= MAX; j += i) {
                p[j] = 0;
            }
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (p[i]) S.push_back(S.back()+i);
    }

    int N; cin >> N;

    int i = 1, j = 0, ans = 0;
    while (i < S.size() && j < i) {
        if (S[i] - S[j] > N) j++;
        else if (S[i] - S[j] < N) i++;
        else {
            ans++; i++; j++;
        }
    }
    cout << ans << '\n';

    return 0;
}
