#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class MaximizingGCD{
    public: int maximumGCDPairing(vector <int> A){
        vector<int> candidates;
        for(int i =1; i<sz(A);i++){
            int sum = A[0]+A[i];
            for(int d=1; d*d<=sum;d++){
                if(sum%d==0){
                    candidates.pb(d);
                    candidates.pb(sum/d);
                }
            }
        }
        int mx= -1;
        for(int c: candidates){
            if(c<=mx)continue;
            vector<int> rem;
            int cntZeroes=0,half=0;
            for(int a: A){
                if(a%c==0){
                    cntZeroes++;
                }else if(2*(a%c)==c){
                    half++;
                }else{
                    rem.pb(a%c);
                }
            }

            if(cntZeroes%2== 0 && half%2==0){
                sort(rem.begin(),rem.end());
                bool can = true;
                for(int i = 0; i<sz(rem)/2;i++){
                    if(rem[i]+rem[sz(rem)-i-1]!= c){
                        can=false;
                    }
                }
                if(can){

                    mx=c;

                }
            }

        }
        return mx;
    };
};

int main(){FIN;
    return 0;
}
