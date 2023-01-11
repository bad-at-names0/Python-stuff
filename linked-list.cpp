#include <bits/stdc++.h>
#define int long long int
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define mod 1000000007
using namespace std;

int32_t main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v;
        string ans = "";

        string x;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.pb(x);
            mp[x]++;
        }

        for (int i = 0; i < n; i++)
        {
            string temp = v[i];
            if (temp.length() == 1)
            {
                ans += '0';
                continue;
            }

            string a, b;
            bool found = false;
            for (int i = 1; i < temp.length(); i++)
            {
                a = temp.substr(0, i);
                b = temp.substr(i, temp.length() - a.length());
                // cout << a << " " << b << endl;
                if (mp[a] and mp[b])
                {
                    // cout << a << " " << b << " " << v[i].second << " " << i << endl;
                    ans += '1';
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans += '0';
            }

            // for (auto &it : ans)
            // {
            //     cout << it;
            // }
            // cout << endl;
        }

        for (auto &it : ans)
        {
            cout << it;
        }
        cout << endl;
    }
    return 0;
}