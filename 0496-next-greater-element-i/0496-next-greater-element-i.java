class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer> m=new HashMap<>();
        Stack<Integer>s=new Stack<>();

        for(int num:nums2){
            while(!s.isEmpty() && s.peek()<num){
                m.put(s.pop(),num);
            }
            s.push(num);
        }

        while(!s.isEmpty()){
            m.put(s.pop(),-1);
        }

        int[] ans=new int[nums1.length];
        for(int i=0;i<nums1.length;i++){
            ans[i]=m.get(nums1[i]);
        }

        return ans;
    }
}