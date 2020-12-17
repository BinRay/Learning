package main

import "fmt"

type Men interface {
	Eat ()
	CanWalk () bool
}

type Singer interface {
	Men
	Sing (song string)
}

type Student struct {
	Name string
	Age int
	School string
}

type Worker struct {
	Name string
	Company string
}

func (s *Student) Eat()  {
	fmt.Println(s.Name, "is eating")
}

func (s *Student) Sing(song string) {
	fmt.Println(s.Name, "is singing", song)
}

func (c *Student) CanWalk() bool {
	return true
}

func main() {
	var h1 Singer = &Student{"yingmu", 16, "xiangbei"}
	fmt.Println(h1)
	h1.Sing("numb")
}

