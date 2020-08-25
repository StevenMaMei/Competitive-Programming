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
class NewBanknote{
    int getCoin(int amount, vector<int> &coins){
        for(int i=sz(coins)-1;i>=0;i--){
            if(coins[i]<=amount)return coins[i];
        }
        assert(false);
    };
    int getAmountCoin(int amount,int newBanknote, vector<int> &coins){
        ll mn = amount;
        for(int i = 0;i<=50000;i++){
            ll currAmount = amount;
            if(i*ll(1)*newBanknote>amount)break;
            ll cant = 0;
            if(i != 0){
                cant = i;
                currAmount-= newBanknote*cant;
            }
            while(currAmount){
                int coin = getCoin(currAmount,coins);
                cant += currAmount/coin;
                currAmount %= coin;
            }
            mn = min(mn,cant);
        }
        return int(mn);
    }
    public: vector <int> fewestPieces(int newBanknote, vector <int> amountsToPay){
        vector<int> cash= {1, 2, 5, 10, 20, 50, 100,  200 ,500, 1000, 2000, 5000, 10000, 20000, 50000};
        sort(cash.begin(),cash.end());
        vector<int> ans;
        fore(i,0,sz(amountsToPay)){
            ans.pb(getAmountCoin(amountsToPay[i],newBanknote,cash));
        }
        return ans;

    };
};

int main(){FIN;
    NewBanknote b;
    vector<int> cash = {53, 9400, 9401, 30000};
    vector<int> ans=b.fewestPieces(4700,cash);
    fore(i,0,sz(ans)){
        cout<<ans[i]<<" ";
    }
    return 0;
}
