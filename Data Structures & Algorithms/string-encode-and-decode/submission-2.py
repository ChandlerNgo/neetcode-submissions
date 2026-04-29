class Solution:

    def encode(self, strs: List[str]) -> str:
        answer = ""
        for s in strs:
            answer += str(len(s))
            answer += '#'
            answer += s
        return answer
    def decode(self, s: str) -> List[str]:
        answer = []
        count = 0
        i = 0
        while i < len(s):
            if s[i] == '#':
                i += 1
                curS = ""
                while count > 0:
                    curS += s[i]
                    count -= 1
                    i += 1
                answer.append(curS)
            else:
                count = count*10 + (ord(s[i])-ord('0'))
                i += 1
        return answer