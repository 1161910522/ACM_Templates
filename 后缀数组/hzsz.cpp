#include <bits/stdc++.h>
using namespace std;
int n, a[100001], b[100001], sum[100001], tmp[100001], id[100001], rk[100010];
char s[100010];
inline bool cmp(int x, int y)
{
    return s[x] < s[y];
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] = s[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1; i <= n; i <<= 1)
    {
        for (int j = 1, t = 0; j <= n; j++)
            rk[id[j]] = a[id[j]] == a[id[j - 1]] && b[id[j]] == b[id[j - 1]] ? t : ++t;
        for (int j = 1; j <= n; j++)
        {
            a[j] = rk[j];
            b[j] = rk[min(i + j, n + 1)];
            id[j] = j;
        }
        for (int j = 0; j < 2; j++)
        {
            memset(sum, 0, sizeof(sum));
            for (int k = 1; k <= n; k++)
                sum[b[k]]++;
            for (int k = 1; k <= n; k++)
                sum[k] += sum[k - 1];
            for (int k = n; k; k--)
            {
                tmp[id[k]] = sum[b[id[k]]]--;
                swap(a[id[k]], b[id[k]]);
            }
            for (int k = 1; k <= n; k++)
                id[tmp[k]] = k;
        }
    }
    for (int i = 1; i < n; i++)
        printf("%d ", rk[i]);
    printf("%d\n", rk[n]);
    return 0;
}
