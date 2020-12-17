package main

import "fmt"

func main(){
	// 普通判断
	var x int64
	fmt.Scanln(&x)
	if x > 5 {
		fmt.Println("x is greater than 5")
	} else {
		fmt.Println("x is less than 5")
	}

	// 声明变量
	if y := x + 1; y > 10 {
		fmt.Println("y is greater than 10")
	} else if y == 10 {
		fmt.Println("y is equal to 10")
	} else {
		fmt.Println("y is less than 10")
	}
}
