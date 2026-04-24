// Last updated: 4/24/2026, 10:07:23 PM
class Solution {
public:


    bool areNumbersAscending(string s) {
        
        int len=s.length();
        int prev=0; // previous number  
        int num=0; // current number 
        for(int i=0;i<len;i++){
           if(s[i]>='0' and s[i]<='9')
                num=(num*10)+s[i]-'0';
            else{
                if(prev==0 and  num>0 ){             
                    prev=num;   // assign num to prev first time
                } 
                else if(prev>0 and num>0){
                 if(prev>=num) return false; // if prev is greater than num
                       prev=num; // store the value of num to prev
                } 
                 num=0;  // reinitialise to num            
           }
        }

    // if till last iteration we get numbers
        if(num>0){
            if(prev>=num) return false;
        }

         return true;
        
    }
};