/**********************************
**@author:Qbright
**@data:20150605
********************************/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums,int target)
    {
        vector<int> result;
        multimap<int,int> map_table;
        for(vector<int>::size_type i=0;i<nums.size();i++)
        {
            map_table.insert(make_pair(nums[i],i));
        }
        for(vector<int>::size_type i=0;i<nums.size();i++)
        {
            multimap<int,int>::iterator it = map_table.find(target-nums[i]);
            int num = map_table.count(target-nums[i]);
            if(it != map_table.end())
            {
                if(num >=1)
                {
                    it++;
                }
                if(it->second!=i)
                {
                    result.push_back(i+1);
                    result.push_back(it->second+1);
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    int mdata[4] = {3,2,4};
    vector<int> data(mdata,mdata+3);
    Solution sol;
    vector<int> result = sol.twoSum(data,6);
    cout << result[0] << " " << result[1] <<endl;
    return 0;
}
