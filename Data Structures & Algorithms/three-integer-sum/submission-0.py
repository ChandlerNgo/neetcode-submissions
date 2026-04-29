class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer = []
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j+1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        numbers = [nums[i],nums[j],nums[k]]
                        numbers.sort()
                        if numbers not in answer:
                            answer.append(numbers)
        return answer