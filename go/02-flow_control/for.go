package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	sum := 0

	// for形式循环
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)

	// while形式循环
	for sum < 1000 {
		sum += sum
	}
	fmt.Println(sum)

	// 迭代循环
	a := []int{0, 1, 2, 3, 4, 5}
	for i, v := range a{
		fmt.Println(i, v)
	}

	// 无线循环与break
	var num int32
	sec := time.Now().Unix()
	rand.Seed(sec)

	for {
		fmt.Print("Writting inside the loop...")
		if num = rand.Int31n(10); num == 5 {
			fmt.Println("finish!")
			break
		}
		fmt.Println(num)
	}



}
