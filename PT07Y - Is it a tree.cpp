#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vll;
#define ff first
#define ss second
#define pb(x) push_back()
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld%lld",&x,&y)
#define slll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pl(x) printf("%lld\n",x)
#define mp make_pair
ll mod=(ll)1e9+7;
const ll INF = (ll)1e18;
#define all(x) x.begin(),x.end()
#define s(x) ((ll)x.size())
#define tc ll t; cin>>t; while(t--)
#define FOR(i,j,n) for(ll i=j;i<n;i++)
#define ig cin.ignore()
#define fast_cin ios_base::sync_with_stdio(false)
ll power(ll a, ll b) {ll ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=mod) ret%=mod;if(a>=mod) a%=mod;b>>=1;}return ret;}
ll inv(ll x) {return power(x,mod-2);}
#define run(m) for(auto it=m.begin(); it!=m.end(); it++)
/*---------------------------------------------------------//
const int MAXM = 1e7+3010;   ll fact[MAXM];
void factorial(){ fact[0]=1;FOR(i,1,MAXM) fact[i]=(fact[i-1]*i)%mod;}
ll nCr(ll n,ll r){return ((fact[n])*(((inv(fact[r]))*(inv(fact[n-r])))%mod))%mod;}

// freopen("Task.in","r",stdin);freopen("Task.out","w",stdout);
//-------------------------------------------------------------------/*/

ll find(ll a,vector<ll>&par){

    if(par[a]!=-1)
        return par[a];

    if(par[a]==-1){
        par[a] = a;
        return a;
    }
    ll temp = find(par[a],par);
    par[a] = temp;
    return temp;
}

void unon(ll a,ll b,vector<ll>&par){
    ll firstset = find(a,par);
    ll secondset = find(b,par);

    if(firstset != secondset){
        par[max(firstset,secondset)] = min(firstset,secondset);
    }
}

int main() {
    fast_cin;
    ll n,m;  sll(n,m);
    pair<ll,ll>p[m];
    vector<ll>par(n+1,-1);

    FOR(i,0,m) {
        sll(p[i].first, p[i].second);

        ll parent1 = find(p[i].first,par);
        ll parent2 = find(p[i].second,par);

        if(parent1 == parent2){
            cout << "NO\n";
            return 0;
        }
        unon(parent1,parent2,par);
    }

    FOR(i,1,n+1){
        if(par[i]==-1){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
