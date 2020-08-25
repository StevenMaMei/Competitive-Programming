#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


int main(){FIN;
    int n,p; cin>>n>>p;
    vector<int> fact(2001);
    fact[0]=1;
    fore(i,1,sz(fact)){
        fact[i]= (fact[i-1]*i)%p;
    }
    vector<int> mons(n);
    fore(i,0,n){
        cin>>mons[i];
    }
    sort(mons.begin(),mons.end());
    vector<int> ans;

    fore(i,0,2001){
        bool met =true;
        int curr= i;
        fore(j,0,n){
            if(curr>= mons[j]){
                curr++;
            }else{
                curr=false;
                break;
            }
        }
        if(!curr)continue;

        auto it1 = upper_bound(mons.begin(),mons.end(),i);
        if(it1 == mons.begin())continue;
        int cant1 = it1 - mons.begin();
        if(cant1 == 0)continue;
        int currCant = cant1;
        int pers = currCant;
        currCant--;
        for(int j=i+1; j<= i+n-1;j++){
            auto it2= upper_bound(mons.begin(),mons.end(),j);
            auto it3= lower_bound(mons.begin(),mons.end(),j);
            int cant2= it2 -it3;
            currCant += cant2;
            pers = (pers * currCant)%p;
            currCant--;
        }
        if(pers){
            ans.pb(i);
        }
    }
    cout<<sz(ans)<<"\n";
    fore(i,0,sz(ans)){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
