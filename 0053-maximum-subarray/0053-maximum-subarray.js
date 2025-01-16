/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let n=nums.length;
    let sum=0;
    let ans=-Infinity;
    for(let i=0;i<n;i++){
        sum+=nums[i];
        if(sum>ans){
            ans=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return ans;
};