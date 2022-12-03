 bool isVowel(char c){
        if(c=='e'||c=='i'||c=='o'||c=='u'||c=='a'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return 1;
        }
        return 0;
    }
    bool halvesAreAlike(string s) {
        int n=s.size()/2;
        int firstVowel=0,SecondVowel=0;
        for(auto i=0;i<n;i++){
            if(isVowel(s[i])){
                firstVowel++;
            }
            if(isVowel(s[n+i])){
                SecondVowel++;
            }
        }
        return firstVowel==SecondVowel;
    }
