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


ll merge(vll &v,vll &temp,ll left,ll mid, ll right){

    ll i=left,j=mid,k=left,cnt=0;

    while((i<=mid-1) && (j<=right)){
        if(v[i] <= v[j])
            temp[k++] = v[i++];
        else{
            temp[k++] = v[j++];
            cnt += (mid - i );
        }
    }

    while(i<=mid-1)
        temp[k++] = v[i++];

    while(j<=right)
        temp[k++] = v[j++];

    FOR(i,left,right+1)
        v[i] = temp[i];

    return cnt;
}

ll merge_sort(vll &v,vll &temp,ll left,ll right){

    ll mid=0,cnt=0;

    if(left >= right)
        return 0;

    mid = left + (right - left)/2;

    cnt += merge_sort(v,temp,left,mid);
    cnt += merge_sort(v,temp,mid+1,right);

    cnt += merge(v,temp,left,mid+1,right);

    return cnt;
}

int main() {
    fast_cin;
    tc{
        ll n;   cin >> n;
        vll v(n),temp(n);

        FOR(i,0,n)
            cin >> v[i];

        cout << merge_sort(v,temp,0,n-1) << "\n";
    }
}
