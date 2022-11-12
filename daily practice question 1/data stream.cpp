/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?*/
//      here the smaller is max heap,larger is min heap
    priority_queue<int>smaller;
    priority_queue<int,vector<int>,greater<int>>larger;
    void addNum(int num) {
//          firstly we will add in smaller heap
        smaller.push(num);
//      here we will check if the maximum element in smaller heap is > then minimum element in large   
//          1 st condition
        if(!smaller.empty()&& !larger.empty()&&smaller.top()>larger.top()){
            int ele=smaller.top();
            smaller.pop();
            larger.push(ele);
        }
//          2nd condition when the size becomes greater 
          if(smaller.size()>larger.size()+1){
              int ele=smaller.top();
              smaller.pop();
              larger.push(ele);
          }else if(smaller.size()+1< larger.size()){
             int ele=larger.top();
             larger.pop();
             smaller.push(ele);
         }
        
    }
    
    double findMedian() {
        if(size(smaller)>size(larger)){
            return smaller.top();
        } else if(size(larger)>size(smaller)){
            return larger.top();
        }else 
            return(double)(smaller.top()+larger.top())/2;
    }
};
