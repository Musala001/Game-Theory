#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=0;i<9;i++){
        if(s[i]=='.') cout << "_";
        else cout << s[i];
        if(i%3==2) cout << endl;
        else cout << " ";
    }
}