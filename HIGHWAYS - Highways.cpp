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

ll dijsktra(vector<vector<pair<ll,ll> >>&v,ll s,ll d,ll n,ll m){
    vll dist(n+1,LONG_LONG_MAX);
    vll vis(n+1,0);
    dist[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;


    pq.push({0,s});
    while (pq.size()){
        auto p = pq.top(); pq.pop();
        ll weight = p.first,node = p.second;

        if(vis[node])
            continue;
        vis[node] = 1;

        for(auto it:v[node]){
            dist[it.first] = min(dist[it.first], it.second + weight);
            pq.push({dist[it.first],it.first});
        }
    }
    return dist[d];
}

int main(){
    fast_cin;
    tc{
        ll n,m,s,d,a,b,w;  cin >> n >> m >> s >> d;
        vector<vector<pair<ll,ll> >>v(n+1);

        FOR(i,0,m){
            cin >> a >> b >> w;
            v[a].push_back({b,w});
            v[b].push_back({a,w});
        }

        ll dis = dijsktra(v,s,d,n,m);

        if(dis==LONG_LONG_MAX)
            cout << "NONE\n";
        else
            cout << dis << "\n";

    }
}
