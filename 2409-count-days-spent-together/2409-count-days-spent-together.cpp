class Solution {
public:
    int dayToDay(string date){
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m =stoi(date.substr(0, 2));
        int d=stoi(date.substr(3, 2));
        
        int dayNumber = d;
        for (int i=0;i<m-1;i++){
            dayNumber += months[i];
        }
        return dayNumber;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrive_Alice = dayToDay(arriveAlice);
        int depart_Alice = dayToDay(leaveAlice);
        int arrive_bob = dayToDay(arriveBob);
        int depart_bob = dayToDay(leaveBob);

        int staying = max(arrive_Alice,arrive_bob);
        int leaving = min(depart_Alice,depart_bob);

        if(staying <= leaving){
            return leaving - staying+1;
        }

        return 0;
    }
};