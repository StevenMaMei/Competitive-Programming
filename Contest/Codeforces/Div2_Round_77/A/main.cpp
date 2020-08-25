#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
int main()
{

    int t; cin>>t;
    while(t--){
        ll c,sum; cin>>c>>sum;
        if(c>=sum){
            cout<<sum<<"\n";
        }else{
            ll total= 0;
            ll div = sum/c;
            ll rest = sum - div*c;
            total += pow(div+1,2.0)*rest;
            cout.setf(ios::fixed);
            double t1 = (pow(div,2.0))*(c-rest);
            total =total+ t1;
            cout<<setprecision(0)<<total<<"\n";
            //total += (((ll)(pow(div,2.0)))*(c-rest));
        }
    }
    return 0;
}
