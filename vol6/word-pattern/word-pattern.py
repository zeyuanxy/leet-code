class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        tokens = str.split(' ')
        pattern2token = {}
        token2pattern = {}
        if len(tokens) != len(pattern):
            return False
        for i in range(len(tokens)):
            if pattern[i] in pattern2token:
                token = pattern2token[pattern[i]]
                if token != tokens[i]:
                    return False
                if token2pattern.get(token, '') != pattern[i]:
                    return False
            else:
                if tokens[i] in token2pattern:
                    return False
                token2pattern[tokens[i]] = pattern[i]
                pattern2token[pattern[i]] = tokens[i]
        return True