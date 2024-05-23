from typing import List

class Solution:
    def countElements(self, arr: List[int]) -> int:
        hash_map = set(arr)
        total = 0
        for i in arr:
            if i+1 in hash_map:
                total += 1
        return total
