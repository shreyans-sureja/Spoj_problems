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

bool flag = false;

bool bfs(vector<bool>&vis,ll n,vector<vector<ll>>&v,vll &color){

    queue<ll>q;

    FOR(i,1,n+1){
        if(vis[i])
            continue;

        q.push(i);

        if(color[i]==-1){
            color[i] = 0;
        }

        while(q.size()){
            ll u = q.front();  q.pop();

            for(auto it:v[u]){
                if(color[it]==color[u]){
                    return true;
                }
                if(vis[it])
                    continue;
                color[it] = 1 - color[u];
                q.push(it);
                vis[it] = true;
            }

        }
    }
    return false;
}

int main(){
    fast_cin;
    ll t; cin >> t;
    FOR(w,1,t+1){
        ll n,m,a,b;  cin >> n >> m;
        vll color(n+1,-1);
        vector<vector<ll> >v(n+1);
        vector<bool> vis(n+1,false);

        FOR(i,0,m){
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        flag = bfs(vis,n,v,color);

        cout << "Scenario #" << w << ":\n";
        if(!flag)
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";

    }
}
