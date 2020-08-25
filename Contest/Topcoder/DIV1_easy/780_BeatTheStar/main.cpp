#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class BeatTheStar{
    public: double doesItMatter(int N, int G){
        vector<vector<double>> dp(N+1, vector<double>(N*(N+1)/2));
        dp[0][0]=1.0;
        double maxScore=0;
        for(int i = 1; i<=N;i++)if(i!=G){
            for(int j=0;j<=maxScore;j++){
                dp[i][j]+=dp[i-1][j]/2;
                dp[i][j+i]+=dp[i-1][j]/2;
//                cout<<i<<" "<<dp[i][j+i]<<"\n";
            }
            maxScore+=i;
        }else{
            for(int j=0;j<=maxScore;j++){
                dp[i][j]=dp[i-1][j];

            }
        }
        double total = N*(N+1)/2;
        double ans =0;
        for(int i=0; i<=maxScore;i++){
//            cout<<i<<" "<<dp[N][i]<<"\n";
            if(2*i<total && 2*(i+G)>total)ans+= dp[N][i];
        }
        return ans;
    };
};
//
//int main(){FIN;
//    BeatTheStar b;
//    cout<<b.doesItMatter(5,5);
//    return 0;
//}
