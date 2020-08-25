#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
struct myStack{
    int cnt =0;
    stack<int> s;
    stack<int> mins;
    stack<int> maxs;

    void push(int v){
        cnt+= v;
        s.push(v);
        mins.push(mins.size() ? min(mins.top(), cnt):cnt);
        maxs.push(maxs.size() ? max(maxs.top(),cnt):cnt);
    }

    void pop(){
        if(s.size() == 0)
            return;
        cnt-= s.top();
        s.pop();
        mins.pop();
        maxs.pop();
    }
    int top(){
        return s.top();
    }

    int getDepth(){
        return maxs.size()? maxs.top():0;
    }
    bool isCorrect(){
        return (mins.size()== 0 || mins.top() >=0) ? true:false;
    }


};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL
    int n; cin>>n;
    string s; cin>> s;
    myStack left,right;
    int pos =0;
    fore(i,0,n){
        right.push(0);
    }
    left.push(0);
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            if(pos > 0){
                pos--;
                right.push(-left.top());
                left.pop();
            }
        }else if(s[i] == 'R'){
            pos++;
            left.push(-right.top());
            right.pop();
        }else if(s[i] == ')'){
            left.pop();
            left.push(-1);
        }else if(s[i] == '('){
            left.pop();
            left.push(1);
        }else{
            left.pop();
            left.push(0);
        }
        if(left.isCorrect() && right.isCorrect() && left.cnt == right.cnt){
            cout<< max({left.getDepth(),right.getDepth(), left.cnt})<<" ";
        }else{
            cout<<"-1 ";
        }
    }
    return 0;
}
