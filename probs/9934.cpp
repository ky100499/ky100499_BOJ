#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
vector<vector<int>> ans;

void solve(int s, int e, int depth)
{
    if (s == e) ans[depth].push_back(nums[s]);
    else {
        int m = (s+e)/2;
        solve(s, m-1, depth+1);
        ans[depth].push_back(nums[m]);
        solve(m+1, e, depth+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int K; cin >> K;
    nums.resize(1<<K); ans.resize(K);
    for (int i = 0; i < (1<<K)-1; i++) cin >> nums[i];

    solve(0, (1<<K)-2, 0);

    for (auto a : ans) {
        for (auto n : a)
            cout << n << ' ';
        cout << '\n';
    }

    return 0;
}
