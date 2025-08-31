def solve(a: list[int], n: int, k: int) -> tuple[int, int, int]:
    
    def valid(v: int) -> tuple[bool, int, int]:
        b = [(1 if x >= v else -1) for x in a]
        p = [0 for _ in range(n)]
        p[0] = b[0]
        for i in range(1, n):
            p[i] = p[i-1] + b[i]

        minm = 0
        index = -1

        for i in range(k-1, n):
            if p[i] - minm >= 0:
                return True, index + 1, i

            if p[i-(k-1)] < minm:
                index = i-(k-1)
                minm = p[index]

        return False, -1, -1
    
    ans = -1
    start = end = -1
    
    lo, hi = min(a), max(a)
    
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        status, cur_start, cur_end = valid(mid)
        if status:
            ans = mid
            start, end = cur_start, cur_end
            lo = mid + 1
        else:
            hi = mid - 1
    
    return ans, start + 1, end + 1



def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        print(" ".join(map(str, solve(a, n, k))))


if __name__ == "__main__":
    main()
