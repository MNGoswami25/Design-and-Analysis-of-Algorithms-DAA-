/*Given a list of activities with their starting time and finishing time. Your goal is to select
maximum number of activities that can be performed by a single person such that selected
activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
activity is greater than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> st, end, ansV;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        st.push_back(temp);
    }
    for (int j = 0; j < n; j++)
    {
        int temp;
        cin >> temp;
        end.push_back(temp);
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({end[i], {st[i], i + 1}});
    }
    auto ct = pq.top();
    pq.pop();
    int ansS = ct.second.first;
    int ansE = ct.first;
    int numA = ct.second.second;
    ansV.push_back(numA);
    ans++;
    while (pq.empty() == false)
    {
        auto it = pq.top();
        pq.pop();
        int e = it.first;
        int s = it.second.first;
        int num = it.second.second;
        if (ansE <= s)
        {
            ansV.push_back(num);
            ansS = s;
            ansE = e;
            ans++;
        }
    }
    cout << "No.of Non Conflicting Activities: " << ans << endl;
    cout << "List of Selected Activities: ";
    for (int i = 0; i < ansV.size(); i++)
    {
        cout << ansV[i] << " ";
    }
    return 0;
}