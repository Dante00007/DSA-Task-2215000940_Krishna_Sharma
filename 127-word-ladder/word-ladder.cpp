class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string str = q.front().first;
            int steps = q.front().second;
            if(str==endWord)
                return steps;
            q.pop();
            for(int i=0;i<str.size();i++){
                char orig = str[i];
                for(char ch= 'a';ch<='z';ch++){
                    str[i] = ch;
                    if(s.contains(str)){
                        q.push({str,steps+1});
                        s.erase(str);
                    }
                }
                str[i] = orig;
            }
        }
        return 0;
    }
};