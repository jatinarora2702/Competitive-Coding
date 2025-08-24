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


def solve(n: int, nums: list[int], cost: list[int]) -> int:
    tot = 0
    while n > 0:
        k = bisect.bisect_right(nums, n) - 1
        tot += cost[k]
        n -= nums[k]
    return tot


def main():
    nums, cost = pre()
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(solve(n, nums, cost))


if __name__ == "__main__":
    main()
