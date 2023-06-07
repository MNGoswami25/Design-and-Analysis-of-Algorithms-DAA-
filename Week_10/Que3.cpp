/*Given an unsorted array of elements, design an algorithm and implement it using a program to
find whether majority element exists or not. Also find median of the array. A majority element is
an element that appears more than n/2 times, where n is the size of array.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v[i] = temp;
    }
    int elem = v[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != elem)
        {
            cnt--;
            if (cnt == 0)
            {
                elem = v[i];
                cnt = 1;
            }
        }
        else
        {
            cnt++;
        }
    }
    int c = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (elem == v[i])
        {
            c++;
            if (c >= n / 2)
            {
                flag = true;
                cout << "Yes" << endl;
                break;
            }
        }
    }
    if (flag == false)
        cout << "NO" << endl;
    if (n % 2 != 0)
    {
        cout << v[n / 2] << endl;
    }
    else
    {
        cout << (v[(n - 1) / 2] + v[n / 2]) / 2.0;
    }
    return 0;
}