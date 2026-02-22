class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> mp=new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }

        PriorityQueue<Integer> q=new PriorityQueue<>((a,b)->mp.get(a)-mp.get(b));

        for(int key:mp.keySet()){
            q.add(key);
            if(q.size()>k){
                q.poll();
            }
        }

        int[] ans=new int[k];
        int i=0;
        while(!q.isEmpty()){
            ans[i++]=q.poll();
        }
        return ans;
    }
}