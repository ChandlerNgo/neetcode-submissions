class Solution:

    def encode(self, strs: List[str]) -> str:
        string = ""
        for word in strs:
            string += word 
            string += "#&*"
        return string
    def decode(self, s: str) -> List[str]:
        answer = s.split("#&*")
        answer.pop()
        return answer
