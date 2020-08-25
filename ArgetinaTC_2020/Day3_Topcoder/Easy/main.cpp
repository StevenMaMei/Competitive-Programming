#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class EllysPronunciation{
    bool isGood(string s){
        int cnt=0;
        for(char c: s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')cnt++;
        }
        if(cnt *2 == sz(s)){
            return true;
        }
        return false;
    }
    public: int getGood(vector <string> words){
        int cnt = 0;
        for(string s: words){
            if(isGood(s)){
                cnt++;
            }
        }
        return cnt;
    };
};

int main(){FIN;
    return 0;
}
