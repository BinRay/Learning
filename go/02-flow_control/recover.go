package main

import "fmt"

func main() {
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("Recovered in main", r)
		}
	}()
	recoverF1(0)
	fmt.Println("Program finished successfully!")
}

func recoverF1(i int) {
	if i > 3 {
		fmt.Println("Panicking!")
		panic("Panic in recoverF1() (major)")
	}
	defer fmt.Println("Defer in recoverF1()", i)
	fmt.Println("Printing in recoverF1()", i)
	recoverF1(i + 1)
}