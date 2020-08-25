#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;

int main()
{FIN;
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        vector<bool> used(26);
        used[s[0]-'a']=true;
        string t(1,s[0]);
        int pos= 0;
        bool can = true;
        fore(i,1,SZ(s)){
            int cur = s[i]-'a';
            if(used[cur]){
                if(pos>0 && t[pos-1]== s[i]){
                    pos--;
                }else if(pos+1<SZ(t) && t[pos+1]==s[i]){
                    pos++;
                }else{
                    cout<<"NO\n";
                    can=false;break;
                }
            }else{
                if(pos==0){
                    t = s[i]+t;
                }else if(pos +1 == SZ(t)){
                    t += s[i];
                    pos++;
                }else{
                    cout<<"NO\n";
                    can=false;break;
                }
            }
            used[cur]=true;
        }
        if(can){
            cout<<"YES\n";
            fore(i,0,26){
                if(!used[i]) t+= char('a'+i);
            }
            cout<<t<<"\n";

        }
    }
    return 0;
}
