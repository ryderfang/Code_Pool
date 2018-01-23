class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        dic = {}
        for n in nums1:
            if nums2.count(n) > 0:
                dic[n] = 1
        return dic.keys()
