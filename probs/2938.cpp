#include <bits/stdc++.h>

using namespace std;

queue<int> A[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        A[n%3].push(n);
    }

    if (A[0].size() > (N+1)/2) cout << "-1\n";
    else if (A[0].empty() && !A[1].empty() && !A[2].empty()) cout << "-1\n";
    else {
        while (A[0].size() > 1 && !A[1].empty()) {
            cout << A[0].front() << ' ' << A[1].front() << ' ';
            A[0].pop(); A[1].pop();
        }
        while (!A[1].empty()) {
            cout << A[1].front() << ' ';
            A[1].pop();
        }

        while (!A[0].empty() && !A[2].empty()) {
            cout << A[0].front() << ' ' << A[2].front() << ' ';
            A[0].pop(); A[2].pop();
        }
        while (!A[2].empty()) {
            cout << A[2].front() << ' ';
            A[2].pop();
        }

        if (!A[0].empty())
            cout << A[0].front();
        cout << '\n';
    }


    return 0;
}
