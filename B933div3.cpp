// B. Rudolf and 121
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Rudolf has an array a
//  of n
//  integers, the elements are numbered from 1
//  to n
// .

// In one operation, he can choose an index i
//  (2≤i≤n−1
// ) and assign:

// ai−1=ai−1−1
// ai=ai−2
// ai+1=ai+1−1
// Rudolf can apply this operation any number of times. Any index i
//  can be used zero or more times.

// Can he make all the elements of the array equal to zero using this operation?

#include <bits/stdc++.h>

using namespace std;

#define ll     long long
#define _test   int _TEST; cin>>_TEST; while(_TEST--)
#define ff     first
#define ss     second
#define pb     push_back

int main()
{
    _test
    {
        int n;
        cin>>n;

        vector<int> a(n);
        for(auto &e: a)     cin>>e;

        int f = 1;

        for(int i=0; i<n-2; i++)
        {
            if(a[i] < 0)        break;

            a[i+1] -= 2*a[i];
            a[i+2] -= a[i];
            a[i] = 0;
        }

        if(count(a.begin(), a.end(), 0) == n)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}