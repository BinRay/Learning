package main

import "fmt"

type Human struct {
	name string
	age int
}

type Student struct {
	Human
	School string
}

func main() {
	h1 := Student{
		Human{
			"yingmu",
			16,
		},
		"xiangbei",
	}

	var h2 Student
	h2.name = "xiandao"
	h2.age = 17
	h2.School = "lingnan"

	h3 := new(Student)
	h3.name = "liuchuanfeng"
	h3.age = 16
	h3.School = "xiangbei"

	h4 := &Human{
		name: "anxi",
		age: 58,
	}

	fmt.Println(h1, h2, h3, h4)
}
