/*Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
matrices together. To find the optimal solution, you need to find the order in which these
matrices should be multiplied.*/

#include <bits/stdc++.h>
using namespace std;
int MCM(vector<int> arr, int N)
{
    int dp[N][N];
    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            arr.push_back(v[i][0]);
            arr.push_back(v[i][1]);
        }
        else
        {
            arr.push_back(v[i][1]);
        }
    }
    cout << MCM(arr, arr.size());
    return 0;
}