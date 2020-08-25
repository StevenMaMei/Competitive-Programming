#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class EpicPartition{


    public: string 	createPartition(int N){
        string s="";
        int sumA=0,sumC=0;
        int D= 6*N;
        if(D*(D+1)%8!= 0)return "";
        int curr =1;
        for(int i = 0;i<N;i++){
            s+="abba";
            sumA+= 2*curr+3;
            curr+=4;
        }
        for(int i = 0;i<N;i++){
            s+="cc";
            sumC+= 2*curr+1;
            curr+=2;
        }
        fore(i,0,sz(s))if(s[i]=='c'){
            int x= i;
            while(2*sumA<sumC){
                if(x==0 || s[x-1]=='c')break;
                swap(s[x],s[x-1]);
                swap(s[x-1],s[x-2]);
                x-=2;
                sumC-=2;
                sumA++;
            }
        }
        return s;
    };

};
//
//int main(){FIN;
//    EpicPartition hello;cout<<hello.createPartition(4);
//    return 0;
//}


