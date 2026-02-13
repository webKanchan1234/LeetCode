class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> s=new Stack<>();



        for(int ast:asteroids){
            boolean destr=false;

            while(!s.isEmpty() && s.peek()>0 && ast<0){
                
                if(s.peek()<-ast){
                    s.pop();
                }else if(s.peek()==-ast){
                    s.pop();
                    destr=true;
                    break;
                }else{
                    destr=true;
                    break;
                }
            }

            if(!destr){
                s.push(ast);
            }
        }

        int[] ans=new int[s.size()];
        for(int i=s.size()-1;i>=0;i--){
            ans[i]=s.pop();
        }

        return ans;
    }
}