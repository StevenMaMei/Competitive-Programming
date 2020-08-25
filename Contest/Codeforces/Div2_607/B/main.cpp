#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;

bool comp(string s1, string s2){
    string ss1 = s1.substr(0,min(s1.size(), s2.size() ));
    string ss2 = s2.substr(0, min(s1.size(), s2.size() ) );
    if(ss1.compare(ss2) < 0){
        return true;
    }
    if(s1.size() < s2.size()){
        bool prefix = true;
        for(int i = 0; i< s1.size(); i++){
            if(s1[i] != s2[i]){
                prefix = false;
                break;
            }
        }
        if(prefix) return true;
    }
    return false;
}
int main()
{

    int t; cin>>t;
    while(t--){
        vector<string> words;
        string s; cin>>s;
        string s2; cin>>s2;

        if(comp(s,s2)){
            cout<<s<<endl;
        }else {
            vector<pair<char,int>> chars;
            for(int i = 0; i<s.size(); i++){
                chars.pb({s[i],i});
            }
            sort(chars.begin(),chars.end());
            int index =0;
            for(int i = 0; i<s.size();i++){
                if(chars[i].ff != s[i]){
                    index = i;
                    break;
                }
            }
            int in=index+1;
            while( in < s.size()&& chars[index].ff == chars[in].ff){
                in++;
            }
            in--;

            int temp = chars[in].ff;
            s[chars[in].ss] = s[index];
            s[index] = temp;
            if(s.compare(s2) <0){
                cout<<s<<endl;
            }else{
                cout<<"---"<<endl;
            }
        }
    }
    return 0;
}
