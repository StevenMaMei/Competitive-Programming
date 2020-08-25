#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;

int main()
{FIN;
    int n, m; cin>>n>>m;
    vector<int> mems(m+1);
    vector<vector<int>> queries(n);

    fore(i,0,m+1)mems[i]= (int)1e9;
    fore(i,0,n){
        int k,c; cin>>k>>c;
        queries[i].pb(c);

        fore(j,0,k){
            int ind ; cin>>ind;
            queries[i].pb(ind);
            mems[ind] = min(mems[ind],c);
        }
    }

    bool can = true;
    fore(i,0,n){
        bool atleast = false;
        fore(j,1,SZ(queries[i])){
            if( mems[queries[i][j]] == queries[i][0]){
                atleast = true;
            }
        }
        can &= atleast;
    }
    if(can){
        cout<<"Good memory\n";
        for(int i = 1; i<= m;i++){
            cout<<mems[i]<<(i==m?"\n":" ");
        }
    }else{
        cout<<"Poor memory\n";
    }
    return 0;
}
