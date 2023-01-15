def solve():
    m = int(input())
    buttons = list(map(int, input().strip().split()))
    
    countOpen = buttons.count(0)
    if (countOpen == 1 and m > 1) or (countOpen == 0 and m == 1):
        print("YES")
    else:
        print("NO")
    

solve()
