from typing import List


def solve(a: List[List[int]], n: int, m: int) -> int:
    maxm = max(max(row) for row in a)
    r, c = -1, -1
    i1, j1, i2, j2 = -1, -1, -1, -1
    found = False
    for i in range(n):
        for j in range(m):
            if a[i][j] != maxm:
                continue
            if i1 < 0 and j1 < 0:
                i1, j1 = i, j
            elif i2 < 0 and j2 < 0:
                i2, j2 = i, j
                if i1 == i2:
                    r = i1
                elif j1 == j2:
                    c = j1
            elif r < 0 and c < 0:
                if i == i1 or j == j2:
                    r = i1
                    c = j2
                elif i == i2 or j == j1:
                    r = i2
                    c = j1
                else:
                    found = True
                    break
            elif r < 0:
                if j != c:
                    r = i
            elif c < 0:
                if i != r:
                    c = j
            elif i != r and j != c:
                found = True
                break
        if found:
            break
    
    if found:
        return maxm
    
    return maxm - 1


def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        a = [list(map(int, input().split())) for _ in range(n)]
        print(solve(a, n, m))


if __name__ == "__main__":
    main()
