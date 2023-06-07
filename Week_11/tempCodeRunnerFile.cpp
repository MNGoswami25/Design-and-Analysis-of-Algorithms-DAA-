#include <bits/stdc++.h>

using namespace std;

bool subsetsum(int n, vector<int> val, int sum)
{
    vector<vector<int>> t(n + 1, vector<int>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                t[i][j] = 1;

            else if (i == 0)
                t[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= val[i - 1])
            {
                t[i][j] = t[i - 1][j - val[i - 1]] || t[i - 1][j];
            }

            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}

int main()
{
    int n;
    cin >> n;

    vector<int> val(n);

    for (int i = 0; i < n; i++)
        cin >> val[i];

    int sum = accumulate(val.begin(), val.end(), 0);

    if (sum % 2 == 1)
        cout << "NO" << endl;

    else
    {
        sum = sum / 2;

        if (subsetsum(n, val, sum))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}