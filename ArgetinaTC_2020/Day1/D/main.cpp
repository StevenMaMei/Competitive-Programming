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
    int n,a,b; cin>>n>>a>>b;
    int vacanttwo=0;
    int denies=0;
    fore(i,0,n){
        int curr; cin>>curr;
        if(curr == 1){
            if(a>0){
                a--;
            }else{
                if(b>0){
                    b--;
                    vacanttwo++;
                }else if(vacanttwo>0){
                    vacanttwo--;
                }
                else{
                    denies++;
                }
            }
        }else{
            if(b>0)b--;
            else denies+=2;
        }
    }
    cout<<denies<<"\n";
    return 0;
}
