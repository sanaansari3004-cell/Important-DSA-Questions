
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int i = 0;
        int j = 0;
        int n = firstList.size();
        int m = secondList.size();

        vector<vector<int>> ans;

        while (i < n && j < m) {
            
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];

            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if (start1 <= start2) {
                if (end1 >= start2) {
                    int start = max(start1, start2);
                    int end = min(end1, end2);
                    ans.push_back({start, end});
                }
            }
            else {
                if (end2 >= start1) {
                    int start = max(start1, start2);
                    int end = min(end1, end2);
                    ans.push_back({start, end});
                }
            }

            if (end1 <= end2) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};
