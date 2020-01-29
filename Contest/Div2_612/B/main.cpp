#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i =0;i<n;i++)


using namespace std;
typedef long long int ll;
int main()
{
    int n,k; cin>>n>>k;
    map<string,int> cards;
    vector<string> crds(n);
    fore(i,0,n){
        string s; cin>>s;
        cards[s] = i;
        crds[i] = s;;
    }
    ll cant  = 0;
    set<string> terns;
    fore(i,0,n){
        for(int j = i+1;j<n;j++){
            string curr = "";
            for(int l = 0; l <k;l++){
                char a = crds[i][l],b = crds[j][l];
                if(a > b) swap(a,b);
                if(a == 'S' && b == 'T'){
                    curr += "E";
                }else if(a == 'E' && b == 'S'){
                    curr += "T";
                }else if( a == 'E' && b == 'T'){
                    curr += "S";
                }else if( a == b){
                    curr += a;
                }
                        //cout<<a<<endl;
            }
            vector<string> pckd;
            pckd.pb(crds[i]); pckd.pb(crds[j]);
                //cout<<curr<<endl;
            if(cards.find(curr) != cards.end() ){
                pckd.pb(curr);
                sort(pckd.begin(),pckd.end());
                string cc=pckd[0]+"";
                cc+= " ";
                cc+= pckd[1]+"";
                cc+= " ";
                cc+= pckd[2]+"";
                //cout<<cc<<endl;
                if(terns.count(cc)==0){
                    cant++;
                    terns.insert(cc);
                }
            }
        }
    }
    cout<<cant<<endl;
    return 0;
}
