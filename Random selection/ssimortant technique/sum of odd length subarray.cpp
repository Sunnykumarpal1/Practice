/*Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66
 

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000*/
algorithm
1. we will find the contribution of element in all the subarray
2. using the formula (n-i)*(i+1) it is based on their position
3. n-i is contribuition to all the elements to it's right and i+1 is all the elements to it's left
4. since we require a odd length so we will find ceil -> means the upper value eg 5.5 will be equal to 6 
5. we will calculate the contribution of the elements by multiplying to it.
 
  
  int sumOddLengthSubarrays(vector<int>& arr) {
        int n=size(arr);
        int sum=0;
        for(auto i=0;i<n;i++){
            int ans=ceil(((n-i)*(i+1))/2.0);
            sum+=ans*arr[i];
        }
        return sum;
    }
