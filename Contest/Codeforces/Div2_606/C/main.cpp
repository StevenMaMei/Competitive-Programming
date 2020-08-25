#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL
    int t; cin>>t;
    while(t--){
        string s; cin>> s;
        int n =s.size();
        vector<int> pos;
        for(int i =0 ;i< n; i++){
            if(s[i] == 'o'){
                if((i-2 >=0 &&s[i-2]== 't'&& s[i-1]== 'w') && ( i+2 <n&&s[i+1]== 'n' && s[i+2] == 'e')){
                    pos.pb(i+1);
                }else if( i-2 >=0 &&s[i-2]== 't'&& s[i-1]== 'w'){
                    pos.pb(i);
                }else if(i+2 <n&&s[i+1]== 'n' && s[i+2] == 'e'){
                    pos.pb(i+2);
                }
            }
        }
        if(pos.size()== 0){
            cout<<"0"<<endl<<""<<endl;
        }else{
            int sz = pos.size();
            cout<<sz<<endl;
            for(int i =0 ; i< sz;i++){
                if(i +1 == sz){
                    cout<<pos[i]<<endl;
                }else{
                    cout<<pos[i]<<" ";
                }
            }
        }

    }
    return 0;
}
