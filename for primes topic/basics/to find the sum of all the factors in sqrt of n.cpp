/* key poionts is that we can do it using O(n),O(n/2) and using sqrt(n) function this takes O(sqrt(n)* logn) becz since we are traverse sqrt(n) times 
and we know that every time we use O(logn) since we itterate sqrt(n) times so it takes O(sqrt(n)* logn)*/
long long factorSum(int N)
    {
        long long sum=0;
        for(auto i=1;i*i<=N;i++){
            if(N%i==0){
            sum+=i;
            if(i!=(N/i)){
                sum+=N/i;
            }
            }
        }
        return sum;
    }
