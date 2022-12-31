#include <bits/stdc++.h>
#define int long long int
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define mod 1000000007
using namespace std;

bool checkPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int32_t main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        bool flag = false;
        int cnt = 0;

        for (auto &it : mp)
        {
            if (it.second > 1)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (checkPrime(v[i]) == 1)
            {
                cnt++;
            }
        }

        if (cnt % 2 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}