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
    fastio int n;
    cin >> n;
    vector<vector<int>> v(0, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.pb({x, y});
    }
    sort(v.begin(), v.end());
    for (auto &it : v)
    {
        cout << it[0] << " " << it[1] << endl;
    }
    return 0;
}