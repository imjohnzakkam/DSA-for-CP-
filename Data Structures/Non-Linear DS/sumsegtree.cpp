#pragma GCC optimize("O3")

#include<bits/stdc++.h>
#define sp " "
#define endl "\n"
#define MAX 10e9
#define MAXN 100001 
#define inf_int 2e9
#define inf_ll 2e18
#define e 1e-9
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
#define cy cout << "YES" << endl
#define  cn cout << "NO" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;

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

struct segtree {
	ll size;
	vl sums;

	void init (ll n) {
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size, 0LL);
	}

	void build (vl &a, ll x, ll lx, ll rx) {
		// we build the segtree in linear time, using a vector which is passed as an argument to build
		if(rx-lx==1) {
			if(lx < a.size()) {
				sums[x] = a[lx];
			}
			return;
		}
		ll m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void build(vl &a) {
		build(a, 0, 0, size);
	}

	void set (ll i, ll v, ll x, ll lx, ll rx) {
		// the recursive set function runs in nlogn time as we have to check logn times for each iteration.
		// we can also build segtree in linear time.
		if(rx - lx == 1) {
			sums[x] = v;
			return;
		}
		ll m = (lx + rx)/2;
		if(i<m) {
			set(i, v, 2*x+1, lx, m);
		}
		else {
			set(i, v, 2*x+2, m, rx);
		}
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}

	void set (ll i, ll v) {
		set(i, v, 0, 0, size);
	}

	ll sum (ll l, ll r, ll x, ll lx, ll rx) {
		// querying for the sum of the segment [l,r) will take logn time which can't be optimised
		if(lx>=r or l>=rx) return 0;
		if(lx>=l and rx<=r) return sums[x];
		ll m = (lx+rx)/2;
		return sum(l,r,2*x+1,lx,m)+sum(l,r,2*x+2,m,rx);
	}

	ll sum (ll l, ll r) {
		return sum(l,r,0,0,size);
	}
};

void check()
{
	ll n,m;
	cin >> n >> m; // The size of the array and the number of queries
	segtree st;
	st.init(n);
	vl a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	st.build(a);
	while(m--) {
		ll op;
		cin >> op;
		if(op==1) {
			ll i, v;
			cin >> i >> v;
			st.set(i,v);
		}
		else {
			ll l,r;
			cin >> l >> r;
			cout << st.sum(l,r) << endl;
		}
	}
    return ;
}

int32_t main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while(t--)
        check();
    return 0;
}