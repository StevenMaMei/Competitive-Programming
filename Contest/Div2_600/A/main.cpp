#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int t; cin>> t;
    while(t--){
        int n; cin>> n;
        int a[n];
        int b[n];
        int r[n];
        for(int i =0 ; i< n; i++){
            cin>> a[i];
        }
        for(int i =0 ; i< n; i++){
            cin>> b[i];
        }
        bool si= true;
        int mayor=-1e7;
        for(int i =0; i< n;i++){

            r[i]= b[i]-a[i];
            if(r[i]>mayor){
                mayor=r[i];
            }
            if(r[i]<0){
                si=false;
                break;
            }
        }
        int curr=0;
        bool acti= false;
        bool act2= false;
        for(int i =0; i<n&& si;i++){
            if(!acti &&r[i]!= 0){
                curr=r[i];
                acti= true;
            }else if(acti){
                if(!act2&&curr != r[i]){
                    r[i]=0;
                    act2=true;
                }else if(act2){
                    r[i]=0;
                }
            }
        }

        for(int i =0 ;i<n && si;i++){
            if(r[i]!= mayor){
                r[i]=0;
                a[i]+=r[i];
            }else{
                a[i]+= mayor;
            }
        }
        for(int i =0; i<n && si;i++){
            if(a[i]!= b[i]){
                si= false;
            }
        }

        if(mayor <0)
            si=false;
        if(si){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
