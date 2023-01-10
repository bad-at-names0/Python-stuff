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
        int n, m;
        cin >> n >> m;
        vector<int> preptimes(n);
        for (int i = 0; i < n; i++)
        {
            cin >> preptimes[i];
        }

        sort(preptimes.rbegin(), preptimes.rend());

        vector<int> matchWon(n);
        int myWon = 0;
        bool flag = true;

        for (int i = n - 1; i >= 0; i--)
        {
            if (m >= preptimes[i])
            {
                m -= preptimes[i];
                matchWon[i] = i;
                myWon++;
            }
            else
            {
                matchWon[i] = i + 1;
            }
        }

        int rank = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (matchWon[i] > myWon)
            {
                int start = matchWon[i];
                while (i > 0 and matchWon[i] == matchWon[i - 1])
                {
                    i--;
                }
                // if( i == 0 ) {
                //     if(matchWon[0] == start) {

                //     }
                // }
                rank++;
            }
            else
            {
                break;
            }
        }

        cout << rank << endl;
    }
    return 0;
}