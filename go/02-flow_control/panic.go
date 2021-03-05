package main

import "fmt"

func main() {
	panicF1(0)
	fmt.Println("Program finished successfully!")
}

func panicF1(i int) {
	if i > 3 {
		fmt.Println("Panicking!")
		panic("Panic in panicF1() (major)")
	}
	defer fmt.Println("Defer in panicF1()", i)
	fmt.Println("Printing in panicF1()", i)
	recoverF1(i + 1)
}