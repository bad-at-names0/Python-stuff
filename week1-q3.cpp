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
    void Union(int p, int q)
    {
        if (p > q)
        {
            id[q] = p;
            sz[p] += sz[q];
        }
        else
        {
            id[p] = q;
            sz[q] += sz[p];
        }
    }
    int Delete(int p)
    {
        Union(p, p + 1);
        return root(p);
    }
};