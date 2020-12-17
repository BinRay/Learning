package main

import "fmt"

func main() {
	sum := 0
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)

	for sum < 1000 {
		sum += sum
	}
	fmt.Println(sum)

	a := []int{0, 1, 2, 3, 4, 5}
	for i, v := range a{
		fmt.Println(i, v)
	}



}
