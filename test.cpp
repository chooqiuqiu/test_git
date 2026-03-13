#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:

    void processdata(vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = left + ((right - left) >> 1);
        processdata(nums, left, mid);
        processdata(nums, mid + 1, right);
        merage(nums, mid, left, right);
    }

    void merage(vector<int>& nums, int mid, int left, int right)
    {
        if (left == right)
        {
            return;
        }
        int p1 = left;
        int p2 = mid + 1;
        vector<int> sort1;
        while (p1 <= mid && p2 <= right)
        {
            sort1.push_back((nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++]));
        }
        while (p1 <= mid)
        {
            sort1.push_back(nums[p1++]);
        }
        while (p2 <= right)
        {
            sort1.push_back(nums[p2++]);
        }
        for (int i = 0;i < sort1.size();i++)
        {
            nums[left + i] = sort1[i];
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>>vectorlist;
        if (length < 0)
        {
            return vectorlist;
        }
        int min = 0;
        int max = length - 1;
        if ((-(nums[min] + nums[max]) >= nums[max]))
        {
            min++;
            max--;
        }
        while (min < max)
        {   
            if ((-(nums[min] + nums[max]) >= nums[max]))
            {
                min++;
                max--;
            }
            int mid = max - 1;
            while (mid > min)
            {
                if (nums[min] + nums[max] + nums[mid] > 0)
                {
                    mid--;
                }
                else if (nums[min] + nums[max] + nums[mid] == 0)
                {
                    vector<int>v1;
                    v1.push_back(nums[min]);
                    v1.push_back(nums[mid]);
                    v1.push_back(nums[max]);
                    
                    vectorlist.push_back(v1);
                    min++;
                    break;
                }
                else
                {
                    min++;
                    mid = max - 1;
                    break;
                }
            }
            
        }
        return vectorlist;
    }
};


int main()
{
    Solution s1;
    vector<int>nums = {-1,0,1,2,-1,-4};
    int target = 0;
    s1.processdata(nums, 0, nums.size() - 1);
    vector<vector<int>> vectorlist_1;
    vectorlist_1 = s1.threeSum(nums);
    for (int i = 0;i < vectorlist_1.size();i++)
    {
        cout << vectorlist_1[i][0] << "," << vectorlist_1[i][1] << "," << vectorlist_1[i][2] << endl;
    }
    return 0;
}