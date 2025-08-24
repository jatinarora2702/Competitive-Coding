import bisect


def pre() -> tuple[list[int], list[int]]:
    maxm = int(1e9 + 7)
    nums = []
    cost = []
    x = 0
    term = 1
    while term <= maxm:
        nums.append(term)
        cost.append(term * 3 + x * (term // 3))
        term *= 3
        x += 1
    return nums, cost


def solve(n: int, k: int, nums: list[int], cost: list[int]) -> int:
    m = len(nums)
    count = [0 for _ in range(m)]
    
    tot = 0
    while n > 0 and k > 0:
        i = bisect.bisect_right(nums, n) - 1
        count[i] += 1
        tot += cost[i]
        n -= nums[i]
        k -= 1

    if n > 0:
        return -1

    k //= 2
    
    for i in range(m-1, 0, -1):
        minm = min(k, count[i])
        count[i-1] += minm * 3
        tot = tot - minm * cost[i] + (minm * 3) * cost[i-1] 
        k -= minm
        if k == 0:
            break

    return tot


def main():
    nums, cost = pre()
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        print(solve(n, k, nums, cost))


if __name__ == "__main__":
    main()
