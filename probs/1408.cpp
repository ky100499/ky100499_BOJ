#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, m, s, gh, gm, gs, d;
    scanf("%d:%d:%d", &h, &m, &s);
    scanf("%d:%d:%d", &gh, &gm, &gs);
    d = (86400+(gh-h)*3600+(gm-m)*60+gs-s)%86400;
    printf("%02d:%02d:%02d\n", d/3600, (d%3600)/60, d%60);

    return 0;
}
