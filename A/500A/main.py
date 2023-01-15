def solve():
    n, t = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    a.append(1)
    t -= 1
    currentPosition = 0
    while currentPosition < n:
        if currentPosition == t:
            print('YES')
            return
        else:
            currentPosition += a[currentPosition]
    print('NO')
solve()
