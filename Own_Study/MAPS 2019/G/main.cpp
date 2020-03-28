#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define SZ(s) int(s.size())
using namespace std;
queue<char> instructions;
stack<int> st;
bool exe(string s){
    //cout<<s<<" jejje"<<endl;
    if(s == "SS"){
        int sign = instructions.front()=='S'?1:-1;
        instructions.pop();
        char current = instructions.front();
        instructions.pop();
        int num = 0;
        while(current != 'N'){
            num = num<<1;
            if(current == 'T') num = (num|1);
            current = instructions.front();
            instructions.pop();
        }
        num *= sign;
        st.push(num);
       // cout<<"num "<<num<<endl;
        return true;
    }else if(s == "SNS"){
        if(SZ(st) == 0){
            cout<< "Invalid copy operation"<<"\n";
        }else{
            int nn = st.top();
            st.push(nn);
        }
        return true;
    }else if(s== "SNT"){
        if(SZ(st) <2){
            cout<<"Invalid swap operation"<<"\n";
        }else{
            int f = st.top();
            st.pop();
            int s = st.top();
            st.pop();
            st.push(f);
            st.push(s);
        }
        return true;
    }else if(s == "SNN"){
        if(SZ(st)){
            st.pop();
        }else{
            cout<<"Invalid remove operation"<<"\n";
        }
        return true;
    }else if(s == "TSSS"){
        if(SZ(st) <2){
            cout<<"Invalid addition operation"<<"\n";
        }else{
            int f = st.top();
            st.pop();
            int s = st.top();
            st.pop();
            st.push(f+s);
        }
        return true;
    }else if(s== "TSST"){
         if(SZ(st) <2){
            cout<<"Invalid subtraction operation"<<"\n";
        }else{
            int f = st.top();
            st.pop();
            int s = st.top();
            st.pop();
            st.push(s-f);
        }
        return true;
    }else if (s== "TSSN"){
         if(SZ(st) <2){
            cout<<"Invalid multiplication operation"<<"\n";
        }else{
            int f = st.top();
            st.pop();
            int s = st.top();
            st.pop();
            st.push(f*s);
        }
        return true;
    }else if(s=="TSTS"){
        if(SZ(st) <2){
            cout<<"Invalid division operation"<<"\n";
        }else{
            int f = st.top();
            if(f == 0){
                cout<<"Division by zero"<<"\n";
            }else{
                st.pop();
                int s = st.top();
                st.pop();

                st.push(s/f);
            }
        }
        return true;
    }else if(s=="TNST"){
        if(SZ(st)){
            int num = st.top();
            st.pop();
            cout<<num<<"\n";
        }else{
            cout<<"Invalid print operation"<<"\n";
        }
        return true;
    }
    return false;
}
int main()
{
    string s; cin>>s;
    fore(i,0,SZ(s)){
        instructions.push(s[i]);
    }
    string ins="";
    while(instructions.size()){
        ins += instructions.front();
        instructions.pop();
        if(exe(ins)){
            ins = "";
        }
    }
    return 0;
}
