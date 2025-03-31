class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        
        for(int i=0;i<n;i++){
            bool flag = true;
            while(!s.empty() && asteroids[i]<0 && asteroids[s.top()]>0){
                if(asteroids[s.top()]> -asteroids[i]){
                    flag = false;
                    break;
                }
                else{
                    int top = asteroids[s.top()];
                    s.pop();
                    if(-asteroids[i]==top){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                s.push(i);
        }
        vector<int> ans(s.size());
        for(int i=ans.size()-1;i>=0;i--){
            ans[i] = asteroids[s.top()];
            s.pop();
        }
        return ans;
    }
};