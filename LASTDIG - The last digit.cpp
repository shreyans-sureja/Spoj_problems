#include<bits/stdc++.h>
using namespace std;
#define sl(x) scanf("%lld",&x)


int main() {
   	long long a,b,t,i;  sl(t);
   	
   	while(t--){
   		sl(a); sl(b);

        if(a==0 && b!=0){
            printf("0\n");
        }
        else if(b==0){
            printf("1\n");
        }
        else{
            b %= 4;
            if(b%4==0)
            	b = 4;
            else
            	b %= 4;
            a = pow(a,b);
            printf("%lld\n",a%10);
        }
    }
}
