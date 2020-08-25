#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;
typedef pair<int,int> ii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    int t;cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        string t;
        int cant = 0;
        int len = 0;
        while(cant != k){
            if(cant + 1 == k){
                for(int i =0; i<n-len;i++){
                    if(i < (n-len)/2){
                        t+= "(";
                    }else{
                        t+= ")";
                    }
                }
                cant++;
            }else{
                len += 2;
                cant++;
                t += "()";
            }
        }
        vector<ii> subs;
        int qOp=0;
        fore(i,0,n){
            if(s[i]!= t[i]){
                int indexJ=i;
                for(int j = i+1; j<n; j++){
                    if(s[j]== t[i]){
                        indexJ = j;
                        break;
                    }
                }
                reverse(s.begin()+i,s.begin()+indexJ+1);
                qOp++;
                subs.pb({i+1,indexJ+1});
            }
        }
        cout<<qOp<<endl;
        for(int i =0;i<subs.size();i++){
            cout<< subs[i].ff <<" "<<subs[i].ss<<endl;
        }
    }
    return 0;
}
