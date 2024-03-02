class Solution1 {
    public int climbStairs(int n) {
        if (n == 0)
            return 1;
        else if (n == 1)
            return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);

    }

}

class Solution2 {
    public int climbStairs(int n) {
        int[] arr = new int[n + 1];
        arr[0] = 1;
        arr[1] = 1;

        for (int i = 2; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        return arr[n];

    }

}

class Solution3 {
    public int climbStairs(int n) {
        int one = 1, two = 1;
        for (int i = 0; i < n - 1; i++) {
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;

    }

}