#include <bits/stdc++.h>
using namespace std;

// This is the solution which take order  N + M log* N amount of time .. it uses both path compression as well as weighted union

class Solution
{

public:
    int n;
    int *id;
    int *sz;

private:
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
    int findRoot(int);
    bool isConnected(int, int);
    void Union(int, int);
};

int Solution::findRoot(int i)
{
    while (i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

bool Solution::isConnected(int p, int q)
{
    return findRoot(p) == findRoot(q);
}

void Solution::Union(int p, int q)
{
    int i = findRoot(p);
    int j = findRoot(q);
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
