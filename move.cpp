#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int p,r,c;
    cin >> s >> p >> r >> c;
    char mark=(p==0)?'x':'o';
    s[r*3+c]=mark;
    for(int i=0;i<9;i++){
        if(s[i]=='.') cout << "_";
        else cout << s[i];
        if(i%3==2) cout << endl;
        else cout << " ";
    }
}