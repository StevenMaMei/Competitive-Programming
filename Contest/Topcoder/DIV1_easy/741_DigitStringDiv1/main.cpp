#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

class DigitStringDiv1{
    map<ii,ll> dp;
    ll fix(ll val, ll limit){
        while(true){
            if(val> limit) return limit+1;
            else if(val == limit) return limit;
            limit /=10;
        }
    }
    ll solve(int pos, ll curNum, ll X, string S){
        if(pos == sz(S)){
            if(curNum > X){
                return 1;
            }
            return 0;
        }
        if(dp.count({pos,curNum})){
            return dp[{pos,curNum}];
        }
        dp[{pos,curNum}] =  solve(pos+1,curNum,X,S);
        if(curNum>0 || int(S[pos]-'0')!= 0){
            ll newNum = fix(10*curNum + int(S[pos]-'0'),X);
            dp[{pos,curNum}] += solve(pos+1,newNum,X,S);
        }
        return dp[{pos,curNum}];
    }
    public: long long count(string S, int X){
        return solve(0,0,ll(X),S);
    };
};
