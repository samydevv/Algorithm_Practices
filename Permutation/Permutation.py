from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        sol = []
        self.backtrack(nums, res, sol)
        return res

    def backtrack(self, nums: List[int], res: List[List[int]], sol: List[int]):
        if len(sol) == len(nums):
            res.append(sol.copy())
            return

        for n in nums:
            if n not in sol:
                sol.append(n)
                self.backtrack(nums, res, sol)
                sol.pop()


if __name__ == '__main__':
    solution = Solution()
    print(solution.permute([1, 2, 3]))
