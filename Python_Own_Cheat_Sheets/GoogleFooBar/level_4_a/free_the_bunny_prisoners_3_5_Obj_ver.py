class Solution:
    def __init__(self):
        pass

    def solution(self, n, r):
        C = self.Combinatorics()
        repeatations = n - r + 1
        totalCount = C.nCr_count(n, r) * r

        f1 = C.generateCombinations(0, n, n - r + 1)

        # print("(n) C (n-r+1)")
        # for each in f1:
        #     print(each)

        res = [[] for i in range(n)]  # An array of length n consisting of empty arrays
        for i in range(totalCount // repeatations):
            for j in f1[i]:
                res[j].append(i)
        return res

    class Combinatorics:
        def __init__(self):
            self.nCr = [[-1 for i in range(20)] for j in range(20)]
            self.nCr_Generates = [[[['#'] for i in range(20)] for j in range(20)] for k in range(20)]

        def nCr_count(self, n, r):
            if (r == 1):
                return n
            if (r == n):
                return 1
            if (self.nCr[n][r] != -1):
                return self.nCr[n][r]

            self.nCr[n][r] = self.nCr_count(n - 1, r) + self.nCr_count(n - 1, r - 1)
            return self.nCr[n][r]

        def generateCombinations(self, start, n, r):  # Top-Down DP O(n*n*r)
            if (len(self.nCr_Generates[start][n][r]) == 1 and self.nCr_Generates[start][n][r][0] == '#'):
                ret = []
                if (r == 1):
                    for i in range(start, n, +1):
                        newArray = [i]
                        ret.append(newArray)
                elif (r > 1):
                    for i in range(start, n, +1):
                        newArray = [i]
                        response = self.generateCombinations(i + 1, n, r - 1)
                        if (len(response) > 0):
                            for each in response:
                                if (len(each) > 0):
                                    newArray2 = [*newArray, *each]
                                    ret.append(newArray2)
                self.nCr_Generates[start][n][r] = ret
            # else:
            #     print("We will, we will rock DP !!")
            #########################
            return self.nCr_Generates[start][n][r]


print(Solution().solution(5, 3))
