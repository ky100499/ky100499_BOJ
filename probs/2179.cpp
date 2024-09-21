#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<string> S(N);
    vector<pair<string, int>> S_sort(N);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        S[i] = s;
        S_sort[i] = {s, i};
    }
    sort(S_sort.begin(), S_sort.end());

    vector<int> prefix(N);
    int maxlen = 0;
    for (int i = 1; i < N; i++) {
        int prelen = 0, len = min(
            S_sort[i-1].first.length(),
            S_sort[i].first.length()
        );
        while (prelen < len){
            if (S_sort[i-1].first[prelen] != S_sort[i].first[prelen]) break;
            prelen++;
        }
        maxlen = max(maxlen, prelen);
        prefix[S_sort[i-1].second] = max(prefix[S_sort[i-1].second], prelen);
        prefix[S_sort[i].second] = max(prefix[S_sort[i].second], prelen);
    }

    for (int i = 0; i < N; i++) {
        if (prefix[i] == maxlen) {
            for (int j = i+1; j < N; j++) {
                if (prefix[j] == maxlen && S[i].substr(0, maxlen) == S[j].substr(0, maxlen)) {
                    cout << S[i]+'\n'+S[j]+'\n';
                    break;
                }
            }
            break;
        }
    }

    return 0;
}
