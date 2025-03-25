#include <bits/stdc++.h>

using namespace std;

int A[4000000], parent[4000000];

int find(int a)
{
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b) parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        parent[i] = i;
    }
    sort(A, A+M);

    while (K--) {
        int n; cin >> n;
        int i = find(upper_bound(A, A+M, n) - A);
        cout << A[i] << '\n';
        if (i+1 < M) merge(i, i+1);
    }

    return 0;
}
