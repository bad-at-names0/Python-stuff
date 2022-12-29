#include <bits/stdc++.h>
#define int long long int
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define mod 1000000007
using namespace std;

void findlcs(string s, string p, int n, vector<vector<int>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int32_t main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string copys = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        findlcs(s, copys, n, dp);

        cout << dp[n][n] / 2 << endl;
    }
    return 0;
}