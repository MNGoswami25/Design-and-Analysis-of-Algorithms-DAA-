/*Given a knapsack of maximum capacity w. N items are provided, each having its own value and
weight. You have to Design an algorithm and implement it using a program to find the list of the
selected items such that the final selected content has weight w and has maximum value. You can
take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
only a fraction xi of item i, where 0 ≤xi≤ 1.
*/
#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int, pair<int, int>> p, pair<int, pair<int, int>> q)
{
    double r = (double)p.second.first / (double)p.second.second;
    double s = (double)q.second.first / (double)q.second.second;
    return r > s;
}
double fractionalKnapsack(int W, vector<pair<int, pair<int, int>>> arr, int N, map<int, int> &mp)
{
    sort(arr.begin(), arr.end(), cmp);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].second.second <= W)
        {

            W -= arr[i].second.second;
            finalvalue += arr[i].second.first;
            mp[arr[i].first] = arr[i].second.second;
        }
        else
        {
            finalvalue += arr[i].second.first * ((double)W / (double)arr[i].second.second);
            mp[arr[i].first] = W;
            break;
        }
    }
    return finalvalue;
}
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int W;
    cin >> W;
    vector<pair<int, pair<int, int>>> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back({i + 1, {val[i], wt[i]}});
    }
    map<int, int> mp;
    cout << "Maximum Value: " << fractionalKnapsack(W, arr, n, mp) << endl;
    cout << "Item-Weight" << endl;
    for (auto it : mp)
    {
        cout << it.first << "-" << it.second << endl;
    }
    return 0;
}