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
        while (id[i] != i)
        {
            i = id[i];
        }
        return i;
    }

    int find(int i)
    {
        while (i != id[i])
        {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    bool connected(int p, int q)
    {
        return root(p) == root(q);
    }

    void Union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if (i < j)
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