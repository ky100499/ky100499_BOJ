#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> LIS, idx(N); LIS.reserve(N);
    int l = 0;
    for (int i = 0; i < N; i++) {
        int x = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();
        if (x == l) {
            LIS.push_back(A[i]);
            l++;
        }
        else {
            LIS[x] = A[i];
        }
        idx[i] = x;
    }

    vector<vector<int>> num(l), ans(l, vector<int>(1));
    for (int i = N-1; i >= 0; i--) {
        /*
        ** 역순으로 진행하며 해당 값에서 이어질 수 있는 LIS의 개수 세기
        **
        ** 입력 배열에서 어떤 값 뒤에 더 큰 값이 있다면 LIS의 길이가 길어짐
        ** -> 어떤 값 뒤에 LIS 길이가 같고 더 큰 값은 존재하지 않음
        ** -> 역순으로 LIS 길이에 따라 num 벡터에 추가하면 오름차순 유지
        **
        ** num벡터와 ans벡터에 같은 개수의 값이 추가되므로 1:1 대응
        ** -> ans : num 값까지 이어질 수 있는 LIS의 개수
        **
        ** num 배열에서 upper bound 사용
        ** -> 구한 index (x) 는 해당 값보다 작거나 같은 최대의 값
        ** -> index 이전의 값으로는 LIS가 연결될 수 없음
        ** -> 연결 가능한 경우의 수 : 전체 - 연결할 수 없는 개수
        ** -> 길이가 최장이라면 언제나 1이므로 if에서 배제
        */
        int cnt = 1, li = idx[i];
        if (li < l-1) {
            int x = upper_bound(num[li+1].begin(), num[li+1].end(), A[i]) - num[li+1].begin();
            cnt = (ans[li+1].back() - ans[li+1][x]) % MOD;
        }
        num[li].push_back(A[i]);
        ans[li].push_back((cnt+ans[li].back())%MOD);
    }

    cout << l << ' ' << (ans[0].back()+MOD)%MOD << '\n';

    return 0;
}
