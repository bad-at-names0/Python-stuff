#include <bits/stdc++.h>
#define int long long int
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define mod 1000000007
using namespace std;

void findLargeSubs(string s, int &startOfSubs, int &lenOfSub, int start)
{
    for (int i = start; i < s.length();)
    {
        if (s[i] == '1')
        {
            int curLen = 0;
            int b = i;
            while (i < s.length() and s[i] == '1')
            {
                curLen++;
                i++;
            }
            if (curLen > lenOfSub)
            {
                lenOfSub = curLen;
                startOfSubs = b;
            }
        }
        else
        {
            i++;
        }
    }
}

bool alreadyExists1(string s, int k)
{
    int lenOfSub = 0;
    for (int i = 0; i < s.length();)
    {
        if (s[i] == '1')
        {
            int curLen = 0;
            int b = i;
            while (i < s.length() and s[i] == '1')
            {
                curLen++;
                i++;
            }
            if (curLen > lenOfSub)
            {
                lenOfSub = curLen;
            }
        }
        else
        {
            i++;
        }
    }
    return lenOfSub >= k;
}

bool starting0s(string s, int k)
{
    int cnt = 0;
    int i = 0;
    while (i < s.length() and s[i] == '0')
    {
        i++;
        cnt++;
    }
    return cnt >= k;
}

int32_t main()
{
    fastio int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (alreadyExists1(s, k))
        {
            cout << "0\n";
            continue;
        }

        if (starting0s(s, k))
        {
            cout << "1\n";
            continue;
        }

        // find index of 1st 0
        int index1stZero = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                index1stZero = i;
                break;
            }
        }

        int ans = 0;

        // find longest 1 sequence after it
        int startOfSubs;
        int lenOfSubs = 0;
        findLargeSubs(s, startOfSubs, lenOfSubs, index1stZero);
        cout << startOfSubs << " " << lenOfSubs << endl;

        // subtract subs len from k
        k -= lenOfSubs;
        startOfSubs--;
        // now points to 0

        // find starting index of this subs
        while (startOfSubs > 0 and k > 0)
        {
            int flag = 0;
            while (k > 0 and s[startOfSubs] == '0')
            {
                k--;
                startOfSubs--;
                flag = 1;
            }
            if (flag == 1)
                ans++;
            while (k > 0 and s[startOfSubs] == '1')
            {
                k--;
                startOfSubs--;
                flag = 2;
            }
            if (flag == 2)
                ans++;
        }
        // index--
        // ans++ (only on char change) cover remaining len
        cout << ans << endl;
    }
    return 0;
}