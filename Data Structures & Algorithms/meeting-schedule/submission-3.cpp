/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    static bool comparator(const Interval &a, const Interval &b) {
        return a.start < b.start;  // sort by start time
    }
    
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0) return true;
        sort(intervals.begin(),intervals.end(),comparator);


        bool ans=true;

        for(int i=0;i<intervals.size()-1;i++){
            int end=intervals[i].end;
            int start=intervals[i+1].start;

            if(end>start){
                return false;
            }
        }
        return ans;
    }
};
