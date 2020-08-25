#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class ReconstructNumber{
    bool meetCondition(char oper, int n1,int n2){
        if(oper =='<'){
            return n1<n2;
        }else  if(oper =='>'){
            return n1>n2;
        }else if(oper == '='){
            return n1==n2;
        }else{
            return n1 != n2;
        }
    }
    public:  string smallest(string comparisons){
        int dp[sz(comparisons)+5][10];
        fore(i,0,sz(comparisons)+5){
            fore(j,0,10){
                dp[i][j]=0;
            }
        }
        fore(i,0,10){
            dp[0][i] |= (1<<i);
        }
        int suf=1;
        for(int i= sz(comparisons)-1;i>=0;i--){
            char oper = comparisons[i];
            fore(j,0,10){
                fore(k,0,10){
                    if(meetCondition(oper,j,k) && dp[suf-1][k]!= 0){
//                        if(suf==2)
//                        cout<<i<<" "<<oper<<" "<<j<<"  "<<k<<"\n";
                        dp[suf][j] |= (1<<k);
                    }
                }
            }
            suf++;
        }
        string ans = "";
        int next=-1;
        fore(i,1,10){
            if(dp[sz(comparisons)][i]){

                fore(j,0,10){
                    if( ((1<<j)&dp[sz(comparisons)][i]) ){
                        next = j;
                        break;
                    }
                }
                ans += to_string(i);
                if(sz(comparisons)>0)
                    ans += to_string(next);
                break;
            }
        }
        if(next ==-1) return ans;
        int pos = sz(comparisons)-1;
        fore(i,0,sz(comparisons)-1){
            fore(j,0,10){
                if( ((1<<j)&dp[pos][next]) ){
                    next = j;
                    break;
                }
            }
            ans += to_string(next);
            pos--;
        }
        return ans;
    };
};
int main(){FIN;
    string s=">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    ReconstructNumber r;
    cout<<r.smallest(s);
    return 0;
}
