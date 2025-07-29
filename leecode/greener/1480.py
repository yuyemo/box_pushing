class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        i=1
        l=len(nums)
        t=[nums[0]]
        while i<l:
            t.append(nums[i]+t[i-1])
            i+=1
        return t
