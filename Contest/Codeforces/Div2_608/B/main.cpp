#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

string s;int n;
void neg(int pos){
    if(s[pos] == 'B'){
        s[pos] ='W';
    }else{
        s[pos] ='B';
    }
}
int main()
{
    cin>>n;
     cin>>s;
    vector<int> pos;
    for(int i=1;i<n-1;i++){
        if( s[i] != s[i-1]){
            neg(i);neg(i+1);
            pos.pb(i);
        }
    }
    if(s[n-1] != s[n-2]){
        for(int i = 0; i<n-2;i++){

            neg(i);neg(i+1);
            pos.pb(i);
            i = i+1;
        }
    }
    //cout<<s<<endl;
    bool check = true;
    for(int i = 0; i<n && check; i++){
        if(s[0] != s[i]) check=false;
    }
    if(check){
        cout<<pos.size()<<endl;
        fore(i,0,pos.size()){
            cout<< pos[i]+1<<" ";
        }
        cout<<endl;
    }else{
        cout<<"-1"<<endl;
    }
    return 0;
}
