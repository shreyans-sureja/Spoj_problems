#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<double, ll> pdl;
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

double dijsktra(vector<vector<pair<ll,double> >>&v,ll s,ll d,ll n,ll m){
    vector<bool>vis(n+1);
    vector<double>dis(n+1,-1.0);

    priority_queue<pdl>pq;
    pq.push({100.0,s});

    while(pq.size()){
        auto node = pq.top().second;
        auto weight = pq.top().first;    pq.pop();

        if(vis[node])
            continue;

        vis[node] = true;

        for(auto it:v[node]){
            dis[it.first] = max(dis[it.first], (weight * it.second)/100.0);
            pq.push({dis[it.first],it.first});
        }
    }
    return dis[d];
}

int main(){
    while(1){
        ll n,m,a,b;  double w;  sl(n);
        if(n==0)
            break;
        sl(m);

        vector<vector<pair<ll,double> >>v(n+1);

        FOR(i,0,m){
            sll(a,b);  scanf("%lf",&w);
            v[a].push_back({b,w});
            v[b].push_back({a,w});
        }

        double ans = dijsktra(v,1,n,n,m);
        printf("%0.6lf percent\n",ans);
    }
}
