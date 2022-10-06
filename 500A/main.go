package main

import "fmt"

func solve() {
	var n, t int
	fmt.Scanln(&n, &t)

	ceils := []int{}
	t -= 1
	for i := 0; i < n-1; i++ {
		ele := 0
		fmt.Scan(&ele)
		ceils = append(ceils, ele)
	}
	ceils = append(ceils, 1)
	currentPos := 0
	for currentPos < n {
		if currentPos == t {
			fmt.Println("YES")
			return
		}
		currentPos += ceils[currentPos]
	}
	fmt.Println("NO")
}
func main() {
	solve()
}
