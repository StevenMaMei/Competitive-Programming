#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)

using namespace std;

int main()
{
    int n,m,k; cin>>n>>m>>k;

    fore(i,0,k){
        int a,b; cin>>a>>b;
    }
    fore(i,0,k){
        int a,b; cin>>a>>b;
    }

    int cnt=0;
    vector<char> ans;
    fore(i,0,n-1){
        cnt++;
        ans.pb('U');
    }
    fore(i,0,m-1){
        cnt++;
        ans.pb('L');
    }
    int side= false;
    fore(i,0,n){

        if(!side){
            fore(j,0,m-1){
                cnt++;
                ans.pb('R');
            }
            side = !side;
        }else{
            fore(j,0,m-1){
                cnt++;
                ans.pb('L');
            }
            side = !side;
        }
        if(i+1 < n){
            cnt++;
            ans.pb('D');
        }
    }
    cout<<cnt<<"\n";
    fore(i,0,ans.size()){
        if(i+1 == ans.size())
            cout<<ans[i]<<"\n";
        else
        cout<<ans[i];
    }
    return 0;
}
