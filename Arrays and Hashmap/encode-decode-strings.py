'''
* Encode Decode Strings: https://leetcode.com/problems/encode-and-decode-strings/description/
'''


class Solution:

    def encode(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        finstr = ""
        for s in strs:
            finstr += str(len(s)) + '#' + s
        return finstr

    def decode(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        finArr = []
        i = j = 0  # i tracks the start of the length, j scans the string

        while j < len(s):
            if s[j] == '#':
                # Get the total length of the next word
                totlen = int(s[i:j])
                j += 1  # move past '#'
                finArr.append(s[j : j + totlen])  # extract the word
                j += totlen  # move to the next segment
                i = j        # reset i to new starting point
            else:
                j += 1  # keep scanning for '#'

        return finArr
    
# Example usage:
if __name__ == "__main__":
    solution = Solution()    

    # Encoding
    words = ["apple", "banana", "carrot", "", "d#og"]
    encoded = solution.encode(words)
    print("Encoded:", encoded)

    # Decoding
    decoded = solution.decode(encoded)
    print("Decoded:", decoded)
