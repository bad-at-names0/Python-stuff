#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int num, int K)
    {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> q; // This is now a min heap

        for (int i = 0; i <= K; i++)
        {
            q.push(arr[i]);
        }

        int index = 0;

        for (int i = K + 1; i < num; i++)
        {
            arr[index++] = q.top();
            q.pop();
            q.push(arr[i]);
        }

        while (!q.empty())
        {
            arr[index++] = q.top();
            q.pop();
        }

        return vector<int>(arr, arr + num);
    }
};

int main()
{
    Solution S;
    int num = 7;
    int k = 3;
    int arr[7] = {6, 5, 3, 2, 8, 10, 9};
    vector<int> temp = S.nearlySorted(arr, num, k);
    for (auto &it : temp)
    {
        cout << it << " ";
    }

    cout << endl;
    return 0;
}