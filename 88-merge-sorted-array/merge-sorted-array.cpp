class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=0;
        nums1.resize(m);
    
        while( left>=0 && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                right++;
                left--;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    }
};