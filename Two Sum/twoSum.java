class Solution1 {
    public static int[] twoSum(int[] nums, int target) {
        int[] answer = new int[2];

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    answer[0] = i;
                    answer[1] = j;
                    break;
                }

            }
        }
        return answer;

    }
}

class Solution2 {
    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        int[] answer = new int[2];
        
        for (int i = 0; i < nums.length; i++) {
            hashMap.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {
            hashMap.put(nums[i], i);
            if (hashMap.containsKey(target - nums[i]) && i != hashMap.get(target - nums[i])) {
                answer[0] = i;
                answer[1] = hashMap.get(target - nums[i]);
                break;
            }
        }
        return answer;
    }
}