#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>> t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int> ang;
        for(int i = 0; i< s.size();i++){
            if(i+1 == s.size()  && s[i] != 'A'){
                ang.push_back(i+1);
                continue;
            }
            if(s[i] == 'A') ang.push_back(i);

        }
        int mx = 0;
        for(int i = 0; i< ang.size()-1; i++){
           // cout<<ang[i+1] - ang[i]<<endl;
            mx = max(ang[i+1] - ang[i]-1,mx);
        }
        cout<<mx<<endl;
    }
    return 0;
}
