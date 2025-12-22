class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String>s=new HashSet<>(wordList);
        Queue<String>q=new LinkedList<>();
        if (!s.contains(endWord)) return 0;

        q.offer(beginWord);
        int lev=1;
        
        while(!q.isEmpty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                String w=q.poll();
                char[] arr=w.toCharArray();

                for(int j=0;j<arr.length;j++){
                    char org=arr[j];

                    for(char c='a';c<='z';c++){
                        if(org==c) continue;

                        arr[j]=c;
                        String nxt=new String(arr);

                        if (nxt.equals(endWord)) return lev + 1;

                        if (s.contains(nxt)) {
                            s.remove(nxt); 
                            q.offer(nxt);
                        }
                    }
                    arr[j] = org;
                }
            }
            lev++;
        }
        return 0;
    }
}