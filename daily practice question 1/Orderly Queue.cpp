//  so here we will be getting an string and then number of elements selected in one time
//  so here the edge  if more than 1 element is select at a time and in only time any element is selected . so here we can get sorted array as answer.
// so when only 1 element is slected at one time from starting and placed at last . so we will be getting the smallest string from this . By trying all this we 
// can get answer string in lexicographically
// tc->O(n) and sc->O(n) for ans string
string orderlyQueue(string s, int k) {
          string ans=s;
         if(k==1){
             
             s+=s;
             string mini="";
             for(auto i=1;i<ans.size();i++){
                 ans=min(ans,s.substr(i,size(ans)));
             }
             
         }else{
             sort(begin(s),end(s));
              ans=s;
         }
        return ans;
    }
