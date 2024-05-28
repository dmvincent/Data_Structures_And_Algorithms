from collections import defaultdict
import sys

class Solution:
    def maxNumberOfBalloons(self, text: str)-> int:
        hashMap = defaultdict(int)        
        preCheckerSet = set("balloon")
        for letter in text:
            if letter in preCheckerSet:
                hashMap[letter] += 1
        
        for key, val in hashMap.items():
            print("Key:", key, " Val:", val)

        ans = sys.maxsize
        if len(hashMap) == len(preCheckerSet):
            for key, val in hashMap.items():
                if key == 'l' or key == 'o':
                    val = val/2
                ans = min(ans, val)
            return int(ans)
        return 0

if __name__ == "__main__":
    text = "nlaebolko"
    sol = Solution()
    ans = sol.maxNumberOfBalloons(text)
    print(ans)
