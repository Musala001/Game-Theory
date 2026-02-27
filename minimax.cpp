#include <bits/stdc++.h>
using namespace std;

int score(string &b){
    auto win=[&](char x){
        return (b[0]==x && b[1]==x && b[2]==x) || 
               (b[3]==x && b[4]==x && b[5]==x) || 
               (b[6]==x && b[7]==x && b[8]==x) ||
               (b[0]==x && b[3]==x && b[6]==x) ||
               (b[1]==x && b[4]==x && b[7]==x) ||
               (b[2]==x && b[5]==x && b[8]==x) ||
               (b[0]==x && b[4]==x && b[8]==x) ||
               (b[2]==x && b[4]==x && b[6]==x);
    };
    if(win('x')) return 1;
    if(win('o')) return -1;
    if(count(b.begin(),b.end(),'.')==0) return 0;
    return 2;
}

int minimax(string b,int turn){
    int s=score(b);
    if(s!=2) return s;
    vector<int> moves;
    for(int i=0;i<9;i++) if(b[i]=='.') moves.push_back(i);
    if(turn==0){
        int best=-2;
        for(int m:moves){
            b[m]='x';
            best=max(best,minimax(b,1));
            b[m]='.';
        }
        return best;
    } else {
        int best=2;
        for(int m:moves){
            b[m]='o';
            best=min(best,minimax(b,0));
            b[m]='.';
        }
        return best;
    }
}

int main(){
    string b;
    cin >> b;
    int xcount=count(b.begin(),b.end(),'x');
    int ocount=count(b.begin(),b.end(),'o');
    int turn=(xcount==ocount)?0:1;
    int res=minimax(b,turn);
    if(res==1) cout << "X wins" << endl;
    else if(res==-1) cout << "O wins" << endl;
    else cout << "Draw" << endl;
}