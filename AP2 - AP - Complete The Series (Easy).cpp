#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tc ll t; cin>>t; while(t--)
#define FOR(i,j,n) for(ll i=j;i<n;i++)
#define fast_cin ios_base::sync_with_stdio(false)

int main(){
    fast_cin;
    tc{
        ll a3,an3,s=0;   cin >> a3 >> an3 >> s;

        ll n = (2 * s) / (a3 + an3);
        ll d = (an3 - a3) / (n-5);
        ll a = a3  - 2*d;

        cout << n << "\n";

        FOR(i,0,n)
            cout << a + i*d << " ";
        cout << "\n";
    }
}
