#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i = low;i<n;i++)

using namespace std;
typedef long long int ll;
ll total = 0;
vector<int> originals;
int N,C,T;
ll seehow(ll limit){
    ll manx = -1e9;
    int lefting = C-1;
    ll cnt= originals[0];
    fore(i,1,N){
        if(cnt + originals[i] <= limit){
            cnt+= originals[i];
        }else{
            if(lefting>0){
                manx = max(cnt,manx);
                cnt = originals[i];
                lefting--;
                if(lefting==0){
                    manx = max(cnt,manx);
                }
            }else{
                cnt+= originals[i];
                manx = max(cnt,manx);
            }
        }
    }
    //cout<<"heheh "<<manx<<endl;
    ll resu = manx/T;
    if(manx%T != 0) resu++;
    return resu;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

     cin>> N>>C>>T;
    originals.resize(N);
    fore(i,0,N){
        cin>>originals[i];
        total += originals[i];
    }
    ll l=0, r=total;
    ll minx = 1e9;

    while(l<r){
        ll mid = l+(r-l)/2;
        //cout<<mid<<endl;
        if(seehow(mid)<minx){
            minx= seehow(mid);
             r= mid-1;
        }else{
            l = mid+1;
        }
    }
    cout<<minx<<endl;
    return 0;
}
