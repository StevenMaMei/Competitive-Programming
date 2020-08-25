#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;
class 	LexicographicPartition{
    public:  vector <int> positiveSum(int n, vector <int> Aprefix, int seed, int Arange){
        ll A[n];
        for(int i = 0; i< sz(Aprefix); i++){
            A[i]= Aprefix[i];
        }
        ll state = seed;
        for(int i = sz(Aprefix); i<n; i++){
            state = (1103515245 *(ll) state + 12345);
            A[i]= state % (2*Arange+1);
            A[i]=A[i]-Arange;
            state = state % (ll(1)<<31);
        }
        vector<int> ans;
        vector<ll> preSum(n);
        preSum[0]=A[0];
        for(int i = 1; i<n;i++)
            preSum[i]=A[i]+preSum[i-1];
        if(preSum[n-1]<=0){
            ans.pb(-1); return ans;
        }
        ll curSum= 0;
        int curLen = 0;
        for(int i = 0; i<n; i++){
            if(curSum>0){
                if(preSum[n-1]-preSum[i-1]<=0 && preSum[n-1]-preSum[i-1]+curSum>0){
                    curLen++;
                    curSum += A[i];
                }else{
                    ans.pb(curLen);
                    curSum=A[i];
                    curLen=1;
                }
            }else{
                curLen++;
                curSum += A[i];
            }
        }
        if(curLen>0){
            ans.pb(curLen);
        }
            ans.insert(ans.begin(), sz(ans));
             if(sz(ans)>201) ans.resize(201);
        return ans;
    };
};

//int main(){FIN;
//    return 0;
//}
