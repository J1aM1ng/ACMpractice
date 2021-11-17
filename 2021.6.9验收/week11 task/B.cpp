#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int n;
typedef long long ll;
ll sto[1000010];
ll dp[10000010];
ll tmp;
void sol()
{
    for (int i = 1; i <= maxn; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + sto[i] * i);
    }
    cout << dp[maxn] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        ++sto[tmp];
    }
    sol();
    return 0;
}
