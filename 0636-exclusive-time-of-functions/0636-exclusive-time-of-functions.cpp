class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n,0);
        stack<int> st;
        int prevTime = 0;

        for(auto log : logs){
            stringstream ss(log);
            string id_str,type, time_str;

            getline(ss,id_str,':');
            getline(ss,type,':');
            getline(ss,time_str,':');

            int id = stoi(id_str);
            int timestamp = stoi(time_str);

            if(type == "start"){
                if(!st.empty()){
                    result[st.top()] += timestamp - prevTime;
                }
                st.push(id);
                prevTime = timestamp;
            }
            else{
                result[st.top()] += timestamp - prevTime+1;
                st.pop();
                prevTime = timestamp+1;
            }
        }
        return result;
    }
};