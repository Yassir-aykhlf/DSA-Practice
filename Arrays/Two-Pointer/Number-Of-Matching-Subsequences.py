from typing import List

def camelMatch(queries: List[str], pattern: str) -> List[bool]:
    def isMatch(pattern, query) :
        pIndex = 0
        for char in query:
            if pIndex < len(pattern) and char == pattern[pIndex]:
                pIndex += 1
            elif (char.isupper()):
                return False
        return pIndex == len(pattern)
    return [isMatch(pattern, q) for q in queries]

# Tests
print(camelMatch(["FooBar", "FooBarTest", "FootBall"], "FB")) # [True, False, True]
print(camelMatch(["FooBar", "FooBarTest", "FootBall"], "FBar")) # [True, False, True]
print(camelMatch(["FooBar", "FooBarTest", "FootBall"], "FBA")) # [False, False, False]