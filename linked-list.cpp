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
        vector<int> v(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]] = i;
        }

        int cnt = 0;
        if (mp[1] != 1)
        {
            int posT = mp[1];
            swap(v[1], v[mp[1]]);
            mp[v[mp[1]]] = mp[1];
            mp[1] = 1;
            cnt++;
        }
        if (mp[2] != 0)
        {
            int posT = mp[2];
            swap(v[0], v[mp[2]]);
            mp[v[mp[2]]] = mp[2];
            mp[2] = 0;
            cnt++;
        }

        mp.clear();
        for (int i = 2; i < n; i++)
        {
            mp[v[i]] = i;
        }

        // for (auto &it : mp)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }

        // cout << endl;

        for (int i = 2; i < n; i++)
        {
            if (v[i] != i + 1)
            {
                int whereIsVigoing = mp[i + 1];
                swap(v[i], v[mp[i + 1]]);

                mp[v[mp[i + 1]]] = mp[i + 1];
                mp[i + 1] = i;

                //     swap(v[0], v[mp[2]]);
                // mp[v[mp[2]]] = mp[2];
                // mp[2] = 0;
                // // update mp of v[i] and i+1
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}