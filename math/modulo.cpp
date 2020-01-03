/*
Usually we see in CP to ouput a number modulo 10^9+7. We shouldn't modulo in the last so, we will do it in differnt  steps.
modulo is distributive over +,-,* but  not /. i.e;
(a*b)%m==(a%m*b%m)%m
so on for +,-
The code for  this in c++ is given below for n!%1000000007
*/

#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;

ll k=1;

int fact(ll n)
{
    if(n==1)
    {
        return k;
    }
    k=(n%M*fact(n-1)%M)%M;
    return k;
}

int main()
{
    ll n;
    cin >> n;
    fact(n);

        cout << k <<endl;
        return 0;
}
