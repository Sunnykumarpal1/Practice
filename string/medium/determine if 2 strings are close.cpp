  bool closeStrings(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        if(n1<n2){
            return 0;
        }
        set<char>st1,st2;
       vector<int>freq1(26,0),freq2(26,0);
        for(auto i=0;i<n1;i++){
            st1.insert(word1[i]);
            st2.insert(word2[i]);
            
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        if(st1==st2&& freq1==freq2){
            return 1;
        }else
            return 0;
    }
