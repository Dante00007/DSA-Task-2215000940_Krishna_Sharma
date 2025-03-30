class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        int i = 0;
        while(i<operations.size()){
            if(operations[i]=="+"){
                int first = s.top();
                s.pop();
                int second = s.top();
                s.push(first);
                s.push(first+second);
            }
            else if(operations[i]=="D"){
                s.push(s.top()*2);
            }
            else if(operations[i]=="C"){
                s.pop();
            }
            else{
                int n = stoi(operations[i]);
                s.push(n);
            }
            i++;
        }
        
        int score = 0;
        while(!s.empty()){
            score+=s.top();
            s.pop();
        }
        return score;
    }
};