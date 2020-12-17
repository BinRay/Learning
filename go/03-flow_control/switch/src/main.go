package main

import "fmt"

func main() {
	var i int
	fmt.Scanln(&i)

	switch i {
	case 1:
		fmt.Println("input: 1")
	case 2:
		fmt.Println("input: 2")
	case 3:
		fmt.Println("input greater than 2")
		fallthrough
	default:
		fmt.Println("other cases")
	}
}
