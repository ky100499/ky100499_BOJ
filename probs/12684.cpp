#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int C; cin >> C;
    for (int n = 1; n <= C; n++) {
        int M, Q; cin >> M >> Q;

        vector<double> probs({1});
        for (int i = 0; i < Q; i++) {
            vector<double> tmp;
            for (int j = 0; j < 4; j++) {
                double p; cin >> p;
                for (int k = 0; k < probs.size(); k++) {
                    tmp.push_back(probs[k]*p);
                }
            }
            sort(tmp.begin(), tmp.end(), greater<double>());

            int len = min((int)tmp.size(), M);
            probs.resize(len);
            for (int j = 0; j < len; j++) {
                probs[j] = tmp[j];
            }
        }

        double ans = 0;
        for (int i = 0; i < probs.size(); i++) ans += probs[i];
        cout << "Case #" << n << ": " << ans << '\n';
    }

    return 0;
}
