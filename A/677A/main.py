def solve():
    m, n = map(int, input().strip().split())
    ppl_height = list(map(int, input().strip().split()))
    
    result = 0
    for i in range(m):
        if ppl_height[i] > n:
            result += 2
        else:
            result += 1

    print(result)

solve()
