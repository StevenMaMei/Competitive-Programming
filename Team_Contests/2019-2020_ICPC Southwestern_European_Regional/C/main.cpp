#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

void add(string& s){
    bool can = false;
//    cout<<s<<"jejej\n";
    for(int i = sz(s)-1; i>= 0; i--){
        if(s[i]=='9'){
            s[i]='0';
        }else{
            can=true;
            s[i]++;
            break;
        }
    }
    if(!can){
        s = "1"+s;
    }
}

int main(){FIN;
    int n; cin>>n;
    string smallest="";
    fore(i,0,100)smallest+= "9";
    set<string> st;
    fore(i,0,n){
        string s; cin>>s;
        st.insert(s);
        if(s[0]!='-'){
            if(smallest> s){
                smallest=s;
            }
        }
    }

    string ans="";
    reverse(smallest.begin(),smallest.end());
    fore(i,0,sz(smallest)){
        fore(i,0,9){
            if(smallest[i] != char(i+'0') ){
                ans += char(i+'0');
                break;
            }
        }
        if(smallest[i]>ans[sz(ans)-1] || sz(ans)<sz(smallest)){
            break;
        }
    }
    while(st.count(ans)){
        add(ans);
    }
    cout<<ans<<"\n";
    return 0;
}
