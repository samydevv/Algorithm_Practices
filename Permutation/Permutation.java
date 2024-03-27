import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class Permutation {

    public static void main(String[] args) {
        System.out.println(permutation(Arrays.asList(1,2,3)));
    }

    public static List<List<Integer>> permutation (List<Integer> nums){
        List<List<Integer>> result = new ArrayList<>();
        Stack<Integer> sol = new Stack<>();
        backtrack(nums,sol,result);
        return result;
    }

    public static void backtrack(List<Integer> nums, Stack<Integer> sol, List<List<Integer>> result){
        if (sol.size() == nums.size()){
            result.add(new ArrayList<>(sol));
            return;
        }

        for (Integer n:nums){
            if (!sol.contains(n)){
                sol.add(n);
                backtrack(nums,sol,result);
                sol.pop();
            }
        }
    }
}
