import java.util.Arrays;

public class productExceptSelf {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(productExceptSelf(new int[]{-1,1,0,-3,3})));
    }


    public static int[] productExceptSelf(int[] nums) {
        int[] ans =  new int[nums.length];
        int prefix = 1;
        int postfix = 1;
        for(int i=0;i<nums.length;i++){
            ans[i]= prefix;
            prefix *= nums[i];
        }
        for(int i=nums.length-1;i>=0;i--){
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
}



//  1,2,3,4,5,6,7,8,1,2,3,4,5,6

//(1,2,3,4,5,6,7)  (2,3,4,5,6,7,8), (3,4,5,6,7,8,1) (4,5,6,7,8,1,2) (5,6,7,8,1,2,3)  (6,7,8,1,2,3,4)  (7,8,1,2,3,4,5) (8,1,2,3,4,5,6)


// 1,2,3,4,5,1,2,3

// (1,2,3,4) (2,3,4,5)  (3,4,5,1) (4,5,1,2) (5,1,2,3)