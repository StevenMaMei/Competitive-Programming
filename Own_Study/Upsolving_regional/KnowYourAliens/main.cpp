#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    vector<ll> coefficients;
    string data; cin>> data;
    char last = data[0];
    ll corrector= 1;

    coefficients.pb((ll)1);
    ll changes=0;
    for(int i= 1; i< data.size();i++){

        ll lastCarry =0;
        if(data[i]!= last){
            ll root = (long long int)((2*(i)+1)*-1);
            ll currCarry=0;
            //cout<< root<<endl;
            for(int j = 0; j< coefficients.size();j++){
                currCarry = coefficients[j];
                ll mult= (ll)coefficients[j]*(ll)root;
                mult += lastCarry;
                coefficients[j] = mult;
                lastCarry= (ll)currCarry;
            }
            coefficients.pb(currCarry);
            changes++;
            last = data[i];
        }
    }
    cout<< changes<< endl;
    ll len = coefficients.size();
    if((data[0]== 'A'&& changes %2 == 0)||(data[0]=='H'&& changes %2 != 0))
        corrector=-1;
    for(int i = len-1; i>= 0;i--){
        if(i-1== -1){
            cout<<coefficients[i]*corrector<<endl;
        }else{
            cout<<coefficients[i]*corrector<<" ";
        }
    }
    return 0;
}
