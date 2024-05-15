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