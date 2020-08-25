#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

using namespace std;

bool match(string s, string t){
    return s == t;
}
int main()
{FIN;
    string s; cin>>s;

    int m; cin>>m;
    bool can= false;
    int chng = 0;
    if(s.find("desmond") != std::string::npos){
        can= true;
    }
    int sz = s.size();
    while(m--){
        int a; cin>>a; a--;
        char re; cin>>re;
        if(!can){
            chng++;
            s[a]= re;
            int delta = -1;
            int delta2 =-1;
            if(re == 'd'){
                delta = 0;
                delta2 = 6;
            }else if( re == 'e'){
                delta = 1;
            }else if(re == 's'){
                delta = 2;
            }else if( re== 'm'){
                delta = 3;
            }else if( re== 'o'){
                delta = 4;
            }else if( re== 'n'){
                delta = 5;
            }
            if(delta != -1){
                int indx = a-delta;
                if(indx + 6 <sz && indx >=0){
                    string ss = s.substr(indx,7);
                    if(match(ss,"desmond")){
                        can= true;
                    }
                }
            }
            if(delta2 != -1 ){
                int indx = a-delta2;
                if(indx + 6 <sz&& indx >=0){
                    string ss = s.substr(indx,7);
                    if(match(ss,"desmond")){
                        can= true;
                    }
                }
            }
        }

    }
    if(can){
        cout<<"I love you, Desmond!\n"<<chng<<"\n";
    }else{
        cout<<"Goodbye, my love!\n";
    }

    return 0;
}
