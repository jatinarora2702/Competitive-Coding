def solve(a: list[int], n: int) -> str:
    mins = []
    minm = float("inf")
    for x in a:
        if x < minm:
            minm = x
        mins.append(minm)
    maxs = [-float("inf")] * len(a)
    maxm = -float("inf")
    for i in range(len(a)-1, -1, -1):
        if a[i] > maxm:
            maxm = a[i]
        maxs[i] = maxm
    
    ans = []
    for i in range(len(a)):
        if i == 0 or i == len(a) - 1:
            ans.append("1")
        elif mins[i-1] < a[i] < maxs[i+1]:
            ans.append("0")
        else:
            ans.append("1")
    return "".join(ans)


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(a, n))


if __name__ == "__main__":
    main()
