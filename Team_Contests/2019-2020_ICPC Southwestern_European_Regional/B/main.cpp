#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
const int N=2*(1e5)+10;
int sp[N];
int main(){FIN;
    int n; cin>>n;
    int indx=0;
    map<string,int> mp;
    map<int,string> mp2;
    fore(i,0,n){
        string s; cin>>s;

        if(mp.count(s)==0){
            mp[s]=indx;
            mp2[indx]=s;
            sp[indx++]++;
        }else{
            sp[mp[s]]++;
        }
    }
    bool can=false;
    fore(i,0,indx){
        if(n-sp[i]<sp[i]){
            cout<<mp2[i]<<"\n";
            can=true;
        }
    }
    if(!can){
        cout<<"NONE\n";
    }
    return 0;
}
