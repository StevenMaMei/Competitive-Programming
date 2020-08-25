#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)

using namespace std;
typedef long long int ll;
ll mod = 998244353 ;
ll p[1000000];
void pows(){
    p[0]=1;
    fore(i,1,1000000){
        p[i]= p[i-1]*10;
        p[i] %= mod;
    }
}
int main()
{
    ll n;cin>>n;
    vector<ll> answers;
    pows();
    fore(i,1,n){
        ll ans = 0;
        ans+= 2*10*9*p[n-i-1];
        ans %=mod;
        if(n-i-2 >= 0){
            ans += (n-i-1)*10*9*9*p[n-i-2];
            ans %= mod;
        }
        //cout<<i<<" "<< ans<<endl;
        answers.pb(ans);
    }
    answers.pb(10);
    fore(i,0,answers.size()){
        if(i+1!= answers.size())cout<<answers[i]<<" ";
        else cout<<answers[i]<<endl;
    }
    return 0;
}
