class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            sort(intervals.begin(), intervals.end(), cmp);

            vector<Interval> res;

            for (int i = 0;i < intervals.size();) {
                int start = intervals[i].start;
                int end = intervals[i].end;

                while (++i < intervals.size()) {
                    if (intervals[i].start <= end) 
                        end = end > intervals[i].end ? end : intervals[i].end;
                    else
                        break;
                }

                Interval in(start, end);

                res.push_back(in);
            }

            return res;
        }

        static bool cmp(Interval in1, Interval in2) {
            return in1.start < in2.start;
        }
};