/*Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a
program to merge all these files into single file with minimum computation. For given two files
A and B with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy
approach)*/
#include <bits/stdc++.h>
using namespace std;
int sol(vector<int> v)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    int tmp = 0;
    while (pq.size() > 1)
    {
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        int c = f + s;
        tmp += c;
        pq.push(c);
    }
    return tmp;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << sol(v);
    return 0;
}