#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i =a,thxicesi=b; i< thxicesi; i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main()
{FIN;
    int t;  cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> ans;
        vector<int> lowestPrime(1005,-1);
        fore(i,2,1005){
            if(lowestPrime[i]==-1){
                for(int j=i; j<1005;j+=i){
                    lowestPrime[j]= i;
                }
            }
            if(i%lowestPrime[i]== 0 && i/lowestPrime[i]!= 1){
                lowestPrime[i]= lowestPrime[i/lowestPrime[i]];
            }
        }
//        fore(i,2,1005){
//            cout<<i<<" "<<lowestPrime[i]<<endl;
//        }
        map<int,int> ids;
        int cnt= 1;
        vector<int> as;
        fore(i,0,n){
            int a; cin>>a;
            as.pb(a);
            if(ids.find(lowestPrime[a]) == ids.end()){
                ids[lowestPrime[a]] = cnt++;
            }
        }
        cout<<ids.size()<<endl;
        fore(i,0,n){
            cout<<ids[lowestPrime[as[i]]]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
