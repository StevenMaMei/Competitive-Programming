#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef pair<string,int> ii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        bool e11= false;
        bool e00= false;
        map<string, int> s01;
        map<string,int> s10;
        fore(i,0,n){
            string s; cin>>s;
            char ini = s[0];
            char fin = s[s.size()-1];
            if(ini == '1' && fin == '1'){
                e11= true;
            }else if(ini == '0'&& fin == '0'){
                e00 =true;
            }else if(ini == '0'&& fin == '1'){
                s01.insert({s, i});
            }else{
                s10.insert({s,i});
            }
        }
        if(s01.size() < s10.size()){
            swap(s01,s10);
        }
        if(e11 && e00 && (s01.size()+ s10.size())== 0){
            cout<< "-1"<<endl;
        }else if((e11 || e00) && (s01.size()+ s10.size()) == 0){
            cout<<"0"<<endl<<endl;
        }else if(s01.size()-s10.size()<= 1){
            cout<<"0"<<endl<<endl;

        }else{
            map<string,int>:: iterator it;
            vector<ii> ans;
            for(it = s01.begin(); it != s01.end(); it++){
                string cs = it-> first;
                reverse(cs.begin(),cs.end());
                if(s10.find(cs) == s10.end()){
                    ans.pb({it -> first,it -> second});
                }
            }

            int sz = (s01.size() - s10.size())/2;
            cout<<sz<<endl;
            fore(i,0,sz){
                cout<<ans[i].ss+1<<" ";
            }
            cout<<endl;
        }


    }
    return 0;
}
