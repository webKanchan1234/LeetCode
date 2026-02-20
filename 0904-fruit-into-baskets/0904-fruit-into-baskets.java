class Solution {
    public int totalFruit(int[] fruits) {
        int n=fruits.length;
        int l=0;
        int mx=0;
        Map<Integer,Integer> mp=new HashMap<>();

        for(int r=0;r<n;r++){
            mp.put(fruits[r], mp.getOrDefault(fruits[r], 0) + 1);

            if(mp.size()>2){
                while(mp.size()>2){
                    mp.put(fruits[l], mp.get(fruits[l]) - 1);
                    if (mp.get(fruits[l]) == 0) {
                        mp.remove(fruits[l]);
                    }
                    l++;
                }
            }
            if(mp.size()<=2){
                mx=Math.max(mx,r-l+1);
            }
        }
        return mx;
    }
}