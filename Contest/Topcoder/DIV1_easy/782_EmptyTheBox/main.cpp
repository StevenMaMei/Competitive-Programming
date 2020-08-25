#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


class EmptyTheBox{
    double getTotal(int T, int subset){
        int sum = 0;
        for(int i = 0; i<T; i++){
            if((subset&(1<<i) ) !=0)sum+=i+1;
        }
        return sum;
    }
    public: double 	minExpectedPenalty(int D, int T){
        double excess=0;
        while(T>2*D){
            excess+=T; T--;
        }
        vector<double> dp((1<<T)+1);
        vector<double> prob(D*2+1);
        fore(a,1,D+1)fore(b,1,D+1)prob[a+b]+=1.0000000000/double(D*D);
        for(int bag=0; bag<(1<<T);bag++){
            for(int roll = 2; roll<=D*2;roll++){
                double best = getTotal(T,bag);
                for(int subset =1; subset<(1<<T);subset++ ){
                    if((bag&subset)== subset && getTotal(T,subset)== roll)best = min(best,dp[subset^bag]);
                }
                dp[bag] += prob[roll] *best;
            }
        }
        return dp[(1<<T)-1]+excess;
    };
};
