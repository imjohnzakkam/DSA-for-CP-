#pragma GCC optimize("O3")

#include<bits/stdc++.h>
#define sp " "
#define endl "\n"
#define MAX 10e9
#define MAXN 100001 
#define inf_int 2e9
#define inf_ll 2e18
#define e 1e-9
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpl vector<pair<ll,ll>>
#define vpc vector<pair<char,char>>
#define adj_list vector<vl> 
#define umap unordered_map<ll, ll>
#define pll pair<ll,pair<ll, ll>>
#define clr(x) memset(x,0,sizeof(x))
#define set(x,k) memset(x,k,sizeof(x))
ll factorial(ll n){return (n==1 || n==0) ? 1: n * factorial(n - 1);}
ll flag = 0;
#define cy cout << "YES" << endl
#define  cn cout << "NO" << endl
#define yn {if(flag) cy; else cn;}
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


ll spf[MAXN]; 
void sieve() 
{ 
    spf[1] = 1; 
    for (auto i=2; i<MAXN; i++) 
  		spf[i] = i; 
  	for (auto i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
    for (auto i=3; i*i<MAXN; i++) 
    {
        if (spf[i] == i) 
        { 
            for (auto j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
	return;
} 

vl getFactorization(ll x) 
{ 
    vl ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 


void check()
{
	// TH : every integer can be expressed in an unique way as the sum of two or more fibonacci numbers 
	// We follow a greedy approach, get the maximum fibonnaci number at each step 
	ll n;
	cin >> n; // The number
	while(n>0) {
		ll ans;
		ll a=0, b=1, c=1; // base cases of fibonacci
		if(n==0 or n==1) ans = n; 
		while(c<=n) a=b,b=c,c=a+b;
		ans = b; // take ans as b since, it is the largest
		cout << ans << sp;
		n-=ans;
	}
	cout << endl;
    return ;
}

int32_t main()
{
    fastio;
    ll t = 1;
    cin >> t;
    while(t--)
        check();
    return 0;
}