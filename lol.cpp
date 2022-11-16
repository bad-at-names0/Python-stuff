#include <bits/stdc++.h>
#define int long long int
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define mod 1000000007
using namespace std;

string decToBinary(int n)
{
    string o = "";
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i; 
        if (k & 1)      
           o+='1';
        else
            o+='0';
    }
    return o;
}

int32_t main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<int> v(n);
        for (auto &it : v)
        {
            cin >> it;
        }
        vector<string> p(n);
        for (int i = 0; i < n; i++)
        {
            int lol = v[i];
            string s = decToBinary(lol);
            p[i] = s;
        }

        // for(auto& it : p) {
        //     cout << it << endl;
        // }

        int k, l1, r1, l2, r2;


        // vector<vector<string>> lol1;
        // for(int i=0;i<n-1;i++) {
        //     for(int j=i+1;j<n;j++) {
        //         string s3="";
        //         string s1 = p[i];
        //         string s2 = p[j];
        //         for(int k=0;k<32;k++) {
        //             if(s1[k]!=s2[k]) {
        //                s3+='1';
        //             } else {
        //                 s3+='0';
        //             }
        //         }
        //         lol1[i].pb(s3);
        //     }
        // }
        

        while (q--)
        {
            cin >> k >> l1 >> r1 >> l2 >> r2;
            l1--;
            r1--;
            l2--;
            r2--;
            k=31-k;
            int ans = 0;
            // int cnt = 0;
            
            for (int i = l1; i <= r1; i++)
            {
                // cout << p[i] << " " << p[i][k] << endl;
                char bit1 = p[i][k];
                
                for (int j = l2; j <= r2; j++)
                {
                    char bit2 = p[j][k];
                    // cout << bit1 << " " << bit2 << endl;
                   
                    if (bit1 != bit2)
                    {
                        ans++;
                    }
                    // cnt++;
                }
            }

            cout << ans << endl;
        }
    }
    return 0;
}