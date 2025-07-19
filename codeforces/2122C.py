def solve(pt: list[tuple[int, int]], n: int) -> None:
    arr = [(pt[i][0], pt[i][1], i+1) for i in range(n)]
    
    arr.sort(key=lambda tup: tup[0])
    lt = sorted(arr[: n // 2], key=lambda tup: tup[1])
    rt = sorted(arr[n // 2:], key=lambda tup: -tup[1])

    for (_, _, i), (_, _, j) in zip(lt, rt):
        print(f"{i} {j}")


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        pt = [tuple(map(int, input().split())) for _ in range(n)]
        solve(pt, n)


if __name__ == "__main__":
    main()
