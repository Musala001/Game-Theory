#include <bits/stdc++.h>
using namespace std;

bool win(string &b,char x){
    return (b[0]==x && b[1]==x && b[2]==x) || 
           (b[3]==x && b[4]==x && b[5]==x) || 
           (b[6]==x && b[7]==x && b[8]==x) ||
           (b[0]==x && b[3]==x && b[6]==x) ||
           (b[1]==x && b[4]==x && b[7]==x) ||
           (b[2]==x && b[5]==x && b[8]==x) ||
           (b[0]==x && b[4]==x && b[8]==x) ||
           (b[2]==x && b[4]==x && b[6]==x);
}

int main(){
    string b;
    cin >> b;
    if(win(b,'x')) cout << "X wins" << endl;
    else if(win(b,'o')) cout << "O wins" << endl;
    else if(count(b.begin(),b.end(),'.')==0) cout << "Draw" << endl;
    else cout << "In progress" << endl;
}