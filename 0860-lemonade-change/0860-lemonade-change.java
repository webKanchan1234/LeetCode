class Solution {
    public boolean lemonadeChange(int[] bills) {
        int cnt5=0;
        int cnt10=0;
        int n=bills.length;
        for(int b:bills){
            if(b==5){
                cnt5++;
            }else if(b==10){
                if(cnt5>0){
                    cnt5--;
                    cnt10++;
                }else{
                    return false;
                }
            }else{
                if(cnt5>0 && cnt10>0){
                    cnt5--;
                    cnt10--;
                }else if(cnt5>=3){
                    cnt5-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}