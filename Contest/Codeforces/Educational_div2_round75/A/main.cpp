#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


int main(){FIN;
    int t; cin>>t;
    while(t--){
        string s;cin>>s;
        int n = sz(s);
        vector<bool> correct(26);
        char last = s[0];
        int cnt = 1;
        fore(i,1,n){
            if(last == s[i]){
                cnt++;
            }else{
                if(cnt%2){
                    correct[last-'a']=true;
                }
                last = s[i]; cnt=1;
            }
        }
        if(cnt%2){
            correct[last-'a']=true;
        }
        fore(i,0,26){
            if(correct[i]){
                char t = char('a'+i);
                cout<<t;
            }
        }
        cout<<"\n";
    }
    return 0;
}
