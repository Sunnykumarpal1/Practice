#include<bits/stdc++.h>
using namespace std;
string SayandCount(int n){
    if(n==1){
        return "1";
    }
    if(n==2){
        return "11";
    }
      string s="11";
          
    for(auto i=3;i<=n;i++){
        string temp="";
        s+="$";
         int counter=1;
         for(auto j=1;j<s.size();j++){
             if(s[j]!=s[j-1]){
                temp+=to_string(counter);
                temp+=s[j-1];
                counter=1;
            }else{
              counter++;
            }
          }
         s=temp;
       }
        return s;
     } 
int main(){
  string  ans =SayandCount(5);
  cout<<ans;
}
