#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    int t; cin>>t;

    while(t--){

        ll n,k; cin>>n>>k;

        if(k*k>n || k%2!= n%2)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
