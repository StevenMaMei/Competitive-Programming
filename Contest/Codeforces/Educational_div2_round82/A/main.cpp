#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        bool first= false;
        int f=-1,l=-1;
        string s; cin>>s;
        fore(i,0,s.size()){
            if(first==false && s[i]=='1'){
                first = true;
                f=i;
            }
            if(s[i]=='1') l=i;
        }
        int cnt = 0;
        fore(i,f,l+1){
            if(s[i]=='0'){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}
