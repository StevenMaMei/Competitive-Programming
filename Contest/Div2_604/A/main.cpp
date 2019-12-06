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
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int t; cin>> t;
    while(t--){
        string s; cin>>s;
        bool can = true;
        for(int i = 0; i < s.size() && can; i++){
            bool picked[3];
            memset(picked,0,3);
            if(i-1 >= 0){
                picked[s[i-1]-'a'] = true;
            }
            if(i + 1 < s.size() && s[i+1] != '?'){
                picked[s[i+1]-'a'] = true;
            }
            if(s[i] == '?'){
                int nchar = -1;
                char c;
                for(int i = 0; i < 3; i++ ){
                    if(picked[i] == 0){
                        nchar = picked[i];
                        c = 'a'+i;
                        break;
                    }
                }
                if(nchar != -1){
                    s[i] = c   ;
                }else{
                    can = false;
                }
            }else{
                if(i-1 >= 0 && s[i] == s[i-1])
                    can = false;
            }
        }
        if(can)
            cout<< s<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
