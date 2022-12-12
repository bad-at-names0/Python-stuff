#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int *id;
    int *sz;
    Solution(int n)
    {
        this->n = n;
        id = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; i++)
        {
            id[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            sz[i] = 1;
        }
    }
    int root(int i)
    {
        while (i != id[i])
        {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool isConnected()
    {
        for (int i = 0; i < n - 1; i++)
        {
            int p = root(i);
            int q = root(i + 1);
            if (p != q)
            {
                return false;
            }
        }
        return true;
    }
    void Union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if (i == j)
            return;
        if (sz[i] <= sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
};

int main()
{
    int m;
    cin >> m;
    // m contains number of timestamps
    int n;
    cin >> n;
    // n contains the number of members

    int flag = 0;
    Solution S(n);
    while (m--)
    {
        // read which two became friends
        // apply union operation between them
        // run is Connected if its true .. then all are connected and we set flag to 1 and break out of loop
    }
}