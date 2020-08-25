#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
map<string, int> mp;
int validPairs[205][205];
string anim[205];
int frec[205];
int main(){FIN;
    int s,l,n; cin>>s>>l>>n;

    set<string> st;

    fore(i,0,s){
        string a; cin>>a;
        st.insert(a);
    }
    int cnt=0;
    for(string s: st){
        mp[s]=cnt;
        anim[cnt]=s;
        cnt++;
    }
    fore(i,0,l){
        string s1,s2; cin>>s1>>s2;
        validPairs[mp[s1]][mp[s2]]=1;
        validPairs[mp[s2]][mp[s1]]=1;
    }
    vector<int> lin(n);

    fore(i,0,n){
        string a; cin>>a;
        lin[i]= mp[a];
        frec[mp[a]]++;
    }
    vector<int> wObj(n);
    int wObjIndx=0;
    int missing=n;
    vector<int> last(s+1);
    while(missing){
        for(int curr=0; curr<cnt;curr++){
            bool can=true;

            for(int i = last[curr]; i<n;i++){
                if(lin[i]==1e9)continue;
                if(validPairs[curr][lin[i]] ||  lin[i]== curr){
                    if(lin[i]==curr){
                        last[curr]=i;
                        wObj[wObjIndx++]=curr;
                        missing--;
                        lin[i]=1e9;
                        curr=1e9;
                        break;
                    }
                }else{
                    last[curr]=i;
                    break;
                }
            }
        }

    }
    fore(i,0,n){
        cout<<anim[wObj[i]]<<(i+1<n?" ":"\n");
    }
    return 0;
}
