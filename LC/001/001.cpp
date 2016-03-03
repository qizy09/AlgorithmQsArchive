class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, k, n = nums.size();
        vector<int> tmp; tmp.resize(2, 0);
        vector<int> ret; ret.resize(n);

        for (i = 0; i < n; i++) ret[i] = i + 1;
        Qsort(nums, ret, 0, n - 1);
        i = 0;
        for (i = 0; i < n - 1; i++)  if (i == 0 || nums[i] != nums[i - 1])
            if (nums[i] * 2 <= target)
            {
                k = target - nums[i];
                j = findB(nums, k, i + 1, n);
                if (j  > -1)
                {
                    tmp[0] = ret[i]; tmp[1] = ret[j];
                    if (tmp[0] > tmp[1])
                    {
                        j = tmp[0]; tmp[0] = tmp[1]; tmp[1] = j;
                    }
                    return tmp;
                }
            } else break;
        cout<< "Wrong!! No results!"<< endl;
    }
private:
    void Qsort(vector<int> &nums, vector<int> &ind, int l, int r)
    {
        if (l < r){
            int x = nums[(l + r) / 2], i = l, j = r, t;
            while (i <= j)
            {
                while (nums[i] < x) i++;
                while (nums[j] > x) j--;
                if (i <= j)
                {
                    t = nums[i]; nums[i] = nums[j]; nums[j] = t;
                    t = ind[i]; ind[i] = ind[j]; ind[j] = t;
                    i++; j--;
                }
            }
            Qsort(nums, ind, l, j);
            Qsort(nums, ind, i, r);
        }
    }
    int findB(vector<int>& nums, int key, int l, int r)
    {
        if (l >= r) return -1;
        int m = (l + r) / 2;
        if (nums[m] == key) return m;
        if (nums[m] > key) return (findB(nums, key, l, m));
        return findB(nums, key, m + 1, r);
    }
};
