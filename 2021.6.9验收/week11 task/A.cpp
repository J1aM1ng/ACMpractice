#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, tmp;
const ll MOD = 998244353;

ll dp[1000010];
ll pres[1000010];

void sol()
{
    dp[1] = 1;
    pres[0] = 0;
    pres[1] = 1;
    for (int i = 2; i <= n + 1; ++i)
    {
        if (dp[i] == -1)
        {
            dp[i] = 0;
            pres[i] = pres[i - 1];
            continue;
        }
        dp[i] = (pres[i - 1] + MOD - pres[i - k - 1 >= 0 ? i - k - 1 : 0]) % MOD;
        pres[i] = (pres[i - 1] % MOD + dp[i] % MOD) % MOD;
    }
    cout << dp[n + 1] % MOD << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tmp;
        dp[tmp + 1] = -1;
    }
    sol();
    return 0;
}
