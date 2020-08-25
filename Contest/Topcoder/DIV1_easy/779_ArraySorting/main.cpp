#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class 	ArraySorting{
    public :vector <int> arraySort(vector <int> A){
        int n= sz(A);
        vector<vector<int>> dp(n+1,vector<int>(2001));
        vector<vector<int>> dp2(n+1,vector<int>(2001));
        int mxValue = *max_element(A.begin(),A.end());
        for(int currIndx=n-1; currIndx>=0; currIndx--){
            for(int currValue=mxValue; currValue>=1;currValue--){
                int needEdit= (A[currIndx]== currValue?0:1);
                if(currIndx == n-1){
                    dp[currIndx][currValue]=dp2[currIndx][currValue]=needEdit;
                    if(currValue < mxValue) dp2[currIndx][currValue] = min(dp2[currIndx][currValue],dp2[currIndx][currValue+1]);
                }else{
                    dp[currIndx][currValue]=dp2[currIndx][currValue]=needEdit+dp2[currIndx+1][currValue];
                    if(currValue < mxValue) dp2[currIndx][currValue] = min(dp2[currIndx][currValue],dp2[currIndx][currValue+1]);
                }
            }
        }

        vector<int> toR;
        int last=1;
        for(int i=0;i<n;i++){
            int bestEdit=n+5;
            int bestNum=0;
            for(int j=last; j<=mxValue;j++){
                if(bestEdit>dp[i][j]){
                    bestEdit=dp[i][j];
                    bestNum=j;
                }
            }
            last = bestNum;
            toR.pb(last);
        }
        return toR;
    };
};

//int main(){FIN;
//    return 0;
//}
