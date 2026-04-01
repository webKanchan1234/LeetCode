class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // int n=wordList.length;
        Set<String> s=new HashSet<>(wordList);
        Queue<String> q=new LinkedList<>();

        int ans=1;

        if(!s.contains(endWord)){
            return 0;
        }

        q.offer(beginWord);

        while(!q.isEmpty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                String w=q.poll();
                if(w.equals(endWord)) return ans;

                char[] arr=w.toCharArray();

                for(int j=0;j<arr.length;j++){
                    char orch=arr[j];

                    for(char ch='a';ch<='z';ch++){
                        arr[j]=ch;
                        String nw=new String(arr);
                        if(s.contains(nw)){
                            q.offer(nw);
                            s.remove(nw);
                        }
                    }
                    arr[j]=orch;
                }
            }
            ans++;
        }

        return 0;

    }
}