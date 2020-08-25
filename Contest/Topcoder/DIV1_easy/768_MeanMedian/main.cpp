#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class MeanMedian{
    public: int minEffort(int needMean, int needMedian, vector <int> d){
        int mnIndx= sz(d)/2;
        sort(d.begin(), d.end(),greater<int>());
        vector<int> score(sz(d));
        int sum = 0;
        fore(i,mnIndx,sz(d)){
            score[i]=needMedian;
            sum +=needMedian;
        }
        if((needMean)*sz(d) > sum){
            int curIndx = sz(d)-1;
            while(needMean*sz(d)>sum){
                int chg = min(10-score[curIndx],needMean*sz(d)-sum );
                score[curIndx] += chg;
                sum += chg;
                curIndx--;
            }
        }
        int ans = 0;
        fore(i,0,sz(d)){
            ans  += d[i]*score[i];
        }
        return ans;
    };
};

//
//int main(){FIN;
//    return 0;
//}
