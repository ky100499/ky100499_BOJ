#include <iostream>
#include <string.h>

#define LEN 1000000
int dp[LEN];

using namespace std;

int main()
{
    int N;
    memset(dp, LEN, LEN * sizeof(int));
    cin >> N;
    dp[N] = 0;

    while (N) {
        if (N % 3 == 0) {
            dp[N/3] = min(dp[N] + 1, dp[N/3]);
        }
        if (N % 2 == 0) {
            dp[N/2] = min(dp[N] + 1, dp[N/2]);
        }
        dp[N-1] = min(dp[N] + 1, dp[N-1]);
        N--;
    }
    cout << dp[1] << endl;

    return 0;
}
