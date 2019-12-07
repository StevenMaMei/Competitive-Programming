#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef pair<int,int> ii;
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

    int t; cin>> t;
    while(t--){
        int n; cin>> n;
        vector<ii> pairs;
        pairs.resize(n);
        for(int  i= 0; i <n ;i++) {
            int num;
            cin >>num;
            pairs[i]={num, i+1};
        }
        sort(pairs.begin(),pairs.end());
        ll low, high;
        low = pairs[0].ss;
        high = pairs[0].ss;
        ll sum = 0;
        bool beautiNumbers[n];
        memset(beautiNumbers, 0, n);
        for(int  i= 0; i <n ;i++){
            if(low >= pairs[i].ss)
                low = pairs[i].ss;
            else if(high <= pairs[i].ss)
                high = pairs[i].ss;
            sum += pairs[i].ss;
            ll suposedSum = (high*(high+1))/2;
            suposedSum = suposedSum - ((low-1)*low)/2;

            if(sum == suposedSum)
                beautiNumbers[i] = true;
        }
        for(int  i= 0; i <n ;i++){
            if(i + 1 == n)
                cout << beautiNumbers[i]<<endl;
            else
                cout << beautiNumbers[i];
        }
    }
    return 0;
}
