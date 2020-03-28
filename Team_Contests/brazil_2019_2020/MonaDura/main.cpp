#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i = low;i<n;i++)

using namespace std;


typedef pair<int,int> ii;

int M,N,K;
bitset<100020001> room;

void mark(int x,int y,int s){
    fore(i,0,s+1){
        if(x-i>=0&&y+s-i>=0&&x-i<M+1&&y+s-i<N+1)room[(x-i)*(N+1)+y+s-i]=1;
        if(x+i>=0&&y+s-i>=0&&x+i<M+1&&y+s-i<N+1)room[(x+i)*(N+1)+y+s-i]=1;
        if(x-s+i>=0&&y-i>=0&&x-s+i<M+1&&y-i<N+1)room[(x-s+i)*(N+1)+y-i]=1;
        if(x+s-i>=0&&y-i>=0&&x+s-i<M+1&&y-i<N+1)room[(x+s-i)*(N+1)+y-i]=1;
    }
}

bool check(int x,int y){
    return x>=0&&y>=0&&x<M+1&&y<N+1&&room[x*(N+1)+y]!=1;
}


bool possible(){
    queue<ii> cola;
    cola.push(mp(0,0));
    while(!cola.empty()){
        ii u=cola.front();
        cola.pop();
        if(u.ff==M && u.ss==N)return true;
        int x=u.ff+1;
        int y=u.ss;
        if(check(x,y))room[x*(N+1)+y]=1,cola.push(mp(x,y));
        x=u.ff+1;
        y=u.ss+1;
        if(check(x,y))room[x*(N+1)+y]=1,cola.push(mp(x,y));
        x=u.ff;
        y=u.ss+1;
        if(check(x,y))room[x*(N+1)+y]=1,cola.push(mp(x,y));
         x=u.ff-1;
        y=u.ss+1;
        if(check(x,y))room[x*(N+1)+y]=1,cola.push(mp(x,y));
         x=u.ff-1;
        y=u.ss;
        if(check(x,y))room[x*(N+1)+y]=1,cola.push(mp(x,y));
         x=u.ff-1;
        y=u.ss-1;
        if(check(x,y))room[x*(N+1)+y]=1,cola.push(mp(x,y));
         x=u.ff;
        y=u.ss-1;
        if(check(x,y))room[x*(N+1)+y]=1,cola.push(mp(x,y));
         x=u.ff+1;
        y=u.ss-1;
        if(check(x,y))room[x*(N+1)+y]=1,cola.push(mp(x,y));
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N >> K;
    fore(i,0,K){
        int x,y,s;
        cin >> x >> y >> s;
        mark(x,y,s);
        mark(x,y,s-1);
    }
    if(possible()){
        cout << "S\n";
    }else{
        cout << "N\n";
    }
}
