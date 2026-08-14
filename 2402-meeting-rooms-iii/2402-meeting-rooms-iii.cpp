class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        int m = meetings.size();

        // Available rooms: smallest room number first
        priority_queue<int, vector<int>, greater<int>> rooms;

        // Occupied rooms: earliest end time first
        // {endTime, roomNumber}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > occupied;

        for(int i = 0; i < n; i++) {
            rooms.push(i);
        }

        vector<int> count(n, 0);

        sort(meetings.begin(), meetings.end());

        for(int i = 0; i < m; i++) {

            long long start = meetings[i][0];
            long long end = meetings[i][1];

            // Free all rooms whose meetings have ended
            while(!occupied.empty() && occupied.top().first <= start) {
                rooms.push(occupied.top().second);
                occupied.pop();
            }

            // If a room is available
            if(!rooms.empty()) {

                int room = rooms.top();
                rooms.pop();

                occupied.push({end, room});
                count[room]++;
            }

            // If all rooms are occupied
            else {

                auto [freeTime, room] = occupied.top();
                occupied.pop();

                long long duration = end - start;

                occupied.push({freeTime + duration, room});
                count[room]++;
            }
        }

        int answer = 0;

        for(int i = 1; i < n; i++) {
            if(count[i] > count[answer]) {
                answer = i;
            }
        }

        return answer;
    }
};