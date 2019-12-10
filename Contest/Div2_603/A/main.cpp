#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i = low; i<n;i++)


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    int t; cin>> t;
    while(t--){
        int arr[3];
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(begin(arr),end(arr));
        int total = 0;
        if(arr[0]+arr[1] > arr[2]){
            int temp = arr[0]+arr[1] - arr[2];
            temp /=2;
            total += temp;
            arr[0] -= temp;
            arr[1] -= temp;
        }
        total += min(arr[2], arr[0]+arr[1]);
        cout<<total<<endl;
    }
    return 0;
}
