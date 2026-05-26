class Solution {
    boolean canEat(int[] piles, int h, int speed) {
        int total = 0;
        for (int pile : piles) {
            total += (pile + speed - 1) / speed;
            if (total > h) return false;
        }
        return true;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = Arrays.stream(piles).max().getAsInt();

        while(low < high){
            int mid = low + (high - low)/2;
            if(canEat(piles,h,mid)){
                high = mid;
            }else{
                low = mid+1;
            } 
        }
        return low;   
    }
}