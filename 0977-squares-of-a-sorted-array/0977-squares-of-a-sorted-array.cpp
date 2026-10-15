
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> neg, pos;

        for (int i = 0; i < size; i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        int n = neg.size();
        int m = pos.size();

        for (int i = 0; i < n; i++)
            neg[i] = neg[i] * neg[i];

        reverse(neg.begin(), neg.end());

        for (int i = 0; i < m; i++)
            pos[i] = pos[i] * pos[i];

        vector<int> res(n + m);
        int i = 0, j = 0, id = 0;

        while (i < n && j < m) {
            if (neg[i] <= pos[j])
                res[id++] = neg[i++];
            else
                res[id++] = pos[j++];
        }

        while (i < n)
            res[id++] = neg[i++];

        while (j < m)
            res[id++] = pos[j++];

        return res;
    }
};
