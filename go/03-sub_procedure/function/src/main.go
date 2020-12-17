package main

import "fmt"

func max (a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

// 多返回值
func SumAndProduct(a, b int) (int, int){
	return a+b, a*b
}

// 变参
func args (arg ...int) {
	for i, n := range arg {
		fmt.Println("args", i, n)
	}
}

// 函数类型
type testInt func(int) bool

func isEven (i int) bool {
	if i % 2 == 0 {
		return true
	} else {
		return false
	}
}

func filterEven (nums []int, f testInt) []int {
	var filterNum []int
	for _, v := range nums {
		if f(v) {
			filterNum = append(filterNum, v)
		}
	}
	return filterNum
}

func main() {
	var a, b int
	fmt.Scanln(&a)
	fmt.Scanln(&b)

	fmt.Println("bigger number is", max(a, b))

	s, p := SumAndProduct(a, b)
	fmt.Println("sum and product are", s, p)

	args(a, b)

	even := filterEven([]int{1, 2, 3, 4, 5, 6}, isEven)
	fmt.Println(even)

}
