#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class OneHandSort{
    bool isSorted(vector<int>& target, int n){
        fore(i,0,n){
            if(target[i]!= i || target[i]==-1){
                return false;
            }
        }
        return true;
    }
    int findPos(vector<int> &target, int num){
        fore(i,0,sz(target)){
            if(target[i]==num)return i;
        }
        assert(false);
        return 0;
    }
    public:  vector <int> sortShelf(vector <int> target){
        int n= sz(target);
        int ordered[n+1];
        fore(i,0,n){
            ordered[i]=target[i];
        }
        sort(ordered,ordered+n);
        target.resize(n+1);
        vector<int> ans;
        int empSlot= n;
        while(!isSorted(target,n)){
            if(empSlot!= n){
                int pos = findPos(target,empSlot);
                ans.pb(pos);
                target[empSlot]= empSlot;
                empSlot=pos;
            }else{
                int pos =0;
                fore(i,0,n){
                    if(target[i]!= i){
                        pos = i;break;
                    }
                }
                ans.pb(pos);
                target[empSlot]=target[pos];
                empSlot=pos;
            }
        }
        return ans;
    };
};


int main(){FIN;
    return 0;
}
