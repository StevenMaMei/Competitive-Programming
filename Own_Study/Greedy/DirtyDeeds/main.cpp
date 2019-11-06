#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef pair<int,int> ii;


bool ascComp(pair<ii,int> p1, pair<ii,int> p2){
    return p1.ff.ff>p2.ff.ff;
}

bool desComp(pair<ii,int> p1, pair<ii,int> p2){
    return p1.ff.ff<p2.ff.ff;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    vector<pair<ii,int>> gp1,gp2;
    int n; cin>> n;
    for(int cas = 0; cas<n;cas++){
        int a,b;
        cin>>a>>b;
        if(a<b){
            gp1.pb({{a,b}, cas+1});
        }else{
            gp2.pb({{a,b},cas+1});
        }
    }
    if(gp1.size()>gp2.size()){
        sort(gp1.begin(),gp1.end(),ascComp);

        cout<< gp1.size()<<"\n";
        for(int i =0; i< gp1.size();i++){
            if(i== gp1.size()-1){
                cout<<gp1[i].ss<<"\n";
            }else{
                cout<<gp1[i].ss<<" ";
            }
        }
    }else{
        sort(gp2.begin(),gp2.end(),desComp);
        cout<< gp2.size()<<"\n";
        for(int i =0; i< gp2.size();i++){
            if(i== gp2.size()-1){
                cout<<gp2[i].ss<<"\n";
            }else{
                cout<<gp2[i].ss<<" ";
            }
        }
    }
}
