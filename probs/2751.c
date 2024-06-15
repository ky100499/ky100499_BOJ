#include <stdio.h>

int main()
{
    freopen("input.txt", "rt", stdin);

    int N;
    scanf("%d", &N);

    int cnt[2000001] = { 0, };
    int ipt;
    for (int i = 0; i < N; i++) {
        scanf("%d", &ipt);
        cnt[ipt+1000000]++;
    }

    for (int i = 0; i < 2000001; i++)
        if (cnt[i])
            printf("%d\n", i-1000000);
}
