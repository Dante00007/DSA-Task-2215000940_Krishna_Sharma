class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd;
        priority_queue<int> even;

        string str = to_string(num);
        
        for(auto num:str){
            int x = num - '0'; 
            if((x)%2==0){
                even.push(x);
            }
            else{
                odd.push(x);
            }
        }
        string ans = "";
        for(auto num:str){
            int x = num -'0';
            
            if(x%2==0){
                ans+=to_string(even.top());
                even.pop();
            }
            else{
                ans+=to_string(odd.top());
                odd.pop();
            }
        }
        int res = stoi(ans); 
        return res;
    }
};