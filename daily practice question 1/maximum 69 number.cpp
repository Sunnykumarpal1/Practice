// here the logic is very simple we need to get the maximum number by replacing 6->9


int maximum69Number (int num) {
        string str=to_string(num);
        for(auto &i:str){
            if(i=='6'){
                i='9';
                break;
            }
        }
         return stoi(str);
    }
