// #include <bits/stdc++.h>
// #define int long long int
// #define fastio                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);
// #define pb push_back
// #define mod 1000000007
// using namespace std;

// int32_t main()
// {
//     fastio int t;
//     cin >> t;
//     while (t--)
//     {
//         int cnte = 0;
//         int cnto = 0;
//         int n;
//         cin >> n;
//         vector<int> v(n);

//         for (int i = 0; i < n; i++)
//         {
//             cin >> v[i];
//             if (v[i] % 2 == 0)
//                 cnte++;
//             else
//                 cnto++;
//         }

//         map<int, int> mp;
//         bool flag = false;
//         for (auto &it : v)
//         {
//             if (mp[it] and it != 1)
//             {
//                 flag = true;
//                 break;
//             }
//             else
//             {
//                 mp[it]++;
//             }
//         }

//         if (flag)
//         {
//             cout << "NO\n";
//             continue;
//         }

//         if (mp[1] < 2)
//         {
//             if (cnto > 1 and cnte > 1)
//             {
//                 cout << "NO\n";
//             }
//             else
//             {
//                 cout << "YES\n";
//             }
//             continue;
//         }

//         cnto -= mp[1];

//         if (cnto > 1 and cnte > 1)
//         {
//             cout << "NO\n";
//             continue;
//         }

//         cnto += mp[1];

//         if (mp[1] > 1)
//         {
//             // if already satisfied this yes else no
//             flag = false;
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = i + 1; j < n; j++)
//                 {
//                     if (__gcd(v[i], v[j]) != 1)
//                     {
//                         flag = true;
//                         break;
//                     }
//                 }
//                 if (flag)
//                     break;
//             }
//             if (flag)
//             {
//                 cout << "NO\n";
//             }
//             else
//             {
//                 cout << "YES\n";
//             }
//         }
//         else
//         {
//             cout << "YES\n";
//         }
//     }
//     return 0;
// }

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
        map<int, int> mp;
        bool flag = false;
        int cnte = 0;
        int cnto = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2 == 0)
            {
                cnte++;
            }
            else
            {
                cnto++;
            }
        }

        for (auto &it : v)
        {
            if (mp[it] and it != 1)
            {
                flag = true;
                break;
            }
            else
            {
                mp[it]++;
            }
        }

        if (flag)
        {
            cout << "NO\n";
            continue;
        }
        flag = false;

        if (mp[1])
        {
            if (mp[1] > 1)
            {
                cnto -= mp[1];
                cnto++;
                flag = true;
            }
        }

        if (cnto > 1 and cnte > 1)
        {
            cout << "NO\n";
            continue;
        }

        flag = false;
        if (mp[1])
        {
            if (mp[1] < 2)
            {
                cout << "YES\n";
                continue;
            }
            else
            {
                flag = false;
                for (int i = 0; i < n; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (__gcd(v[i], v[j]) != 1)
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                if (flag)
                    cout << "NO\n";
                else
                    cout << "YES\n";
                continue;
            }
        }
        else
        {
            cout << "YES\n";
            continue;
        }
    }
    return 0;
}