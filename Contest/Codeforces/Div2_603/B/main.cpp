#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string> pins;
        pins.resize(n);
        set<string> exist;
        set<string> picked;
        fore(i,0,n) cin>>pins[i], exist.insert(pins[i]);
        int cant = 0;

        fore(i,0,n){
            if(picked.find(pins[i])!=picked.end()){
                string cop = pins[i];
                bool stop = false;
                char c= '0';
                for(int j = 0; j < 4 && !stop; j++){
                    for(int k = 0; k<10 &&!stop;k++){
                        string temp = cop;
                        temp[j] = c+k;
                        if(exist.find(temp) == exist.end()){
                            exist.insert(temp);
                            picked.insert(temp);
                            pins[i] = temp;
                            stop = true;
                            cant++;
                        }
                    }
                }
            }else{
                picked.insert(pins[i]);
            }
        }
        cout<<cant<<endl;
        for(int i = 0; i< n; i++){
                cout<< pins[i]<<endl;
        }

    }
    return 0;
}
