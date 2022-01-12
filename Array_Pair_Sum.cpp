#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mp[nums[i]%k]++;
        }
        if(sum%k!=0)
        return false;
        for(int i=0;i<nums.size();i++)
        {
            int rem=nums[i]%k;
            if(rem==0||2*rem==k)
            {
                if(mp[rem]%2!=0)
                return false;
            }
            else
            {
                if(mp[rem]!=mp[k-rem])
                return false;
            }
        }
        return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} 
