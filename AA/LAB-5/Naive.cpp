#include <bits/stdc++.h>
using namespace std;

int main(){
    string text;
    cout << "Enter the text: ";
    cin >> text;
    
    string pattern;
    cout << "Enter the pattern: ";
    cin >> pattern;

    int n = text.length();
    int m = pattern.length();

    for(int s=0; s<=(n-m); s++){
        int i=0, j=0;
        while(j<m && text[s+i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
           cout << "Pattern occurs at: "; 
           cout << s << endl;
        }
    }
    return 0;
}

