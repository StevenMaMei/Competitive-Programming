#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class  SelfDescFind{
    vector<vector<int>> partitions(int sum, int len){
        vector<vector<int>> ans;
        if(len == 1){
            if(sum>=1 && sum<=9){
                vector<int> op;
                op.pb(sum);
                ans.pb(op);
            }
            return ans;
        }
        for(int i = 1; i<=9 && sum-i>=len-1;i++){
            vector<vector<int>> temp = partitions(sum-i,len-1);
            for(auto cur : temp){
                cur.pb(i);
                ans.pb(cur);
            }
        }
        return ans;
    }
    public:  string construct(vector <int> digits){
        int D = sz(digits);
        vector<vector<int>> opt= partitions(2*D, D);
        string ans="";
        for(vector<int> cur:opt){
            vector<int> actualCnt(10);
            fore(i,0,D) actualCnt[cur[i]]++;
            fore(i,0,D) actualCnt[digits[i]]++;
            vector<int> declareCnt(10);
            fore(i,0,D) declareCnt[digits[i]] = cur[i];
            if(actualCnt != declareCnt) continue;
            vector<int> pairs;
            fore(i,0,D){
                pairs.pb(10*cur[i]+digits[i]);
            }
            sort(pairs.begin(),pairs.end());
            string posAns="";
            fore(i,0,D) posAns+= to_string(pairs[i]);
            if(ans == "")ans= posAns;
            if(ans> posAns)ans=posAns;
        }
        return ans;
    };
};

int main(){FIN;
    return 0;
}
