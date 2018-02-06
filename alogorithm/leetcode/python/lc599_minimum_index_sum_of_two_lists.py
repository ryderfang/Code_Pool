import sys

class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        idx = []
        min_idx = sys.maxsize
        for i in range(len(list1)):
            if list2.count(list1[i]) > 0:
                idx.append(i + list2.index(list1[i]))
            else:
                idx.append(sys.maxsize)
            min_idx = min(min_idx, idx[i])
        ans = []
        for i in range(len(idx)):
            if idx[i] == min_idx:
                ans.append(list1[i])
        return ans
