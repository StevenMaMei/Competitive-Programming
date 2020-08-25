#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class PrimePruning{

    public: string maximize(int N, int E){
        string s="";
        int nz=0;
        int need = N-E;
        for(int i =2;;i++){
            bool prime=true;
            for(int j=2; j*j<=i;j++){
                if(i%j==0){
                    prime=false;
                    break;
                }
            }
            if(!prime)continue;
            s+= char('a'+(i%26) );
            nz += int(s.back()=='z');
            if(nz == need || sz(s)==N)break;
        }
        N= sz(s);
        int start = 0;
        string ans="";
        fore(i,0,need){
            int pos = 0;
            char mx=' ';
            for(int j = start; j<= N-need+i;j++){
                if(s[j]>mx){
                    mx=s[j];
                    pos=j;
                }
            }
            ans += mx;
            start = pos+1;
        }
        return ans;
    };
};

int main(){FIN;
    return 0;
}
