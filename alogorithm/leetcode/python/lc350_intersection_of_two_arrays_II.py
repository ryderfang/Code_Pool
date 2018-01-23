class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort()
        nums2.sort()
        p = 0
        q = 0
        ans = []
        while p < len(nums1) and q < len(nums2):
            if nums1[p] == nums2[q]:
                ans.append(nums1[p])
                p += 1
                q += 1
            elif nums1[p] < nums2[q]:
                p += 1
            else:
                q += 1
        return ans
