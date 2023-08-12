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
    
    int shift[26];
    for(int i=0; i<26; i++){
        shift[i] = m;
    }
    for(int i=0; i<=(m-2); i++){
        shift[pattern[i] - 'a'] = m-i-1;
    }
    int j=0;
    while(j+m <= n){
        if(text[j+m-1] == pattern[m-1]){
           int i = m-2;
           while(i >= 0 && pattern[i] == text[i+j]){
               i--;
           }
           if(i == -1){
              cout << "Pattern occurs at: ";
              cout << j << endl; 
           }
              
        }
        j = j + shift[text[j+m-1]-'a'];
    }
    return 0;
}
