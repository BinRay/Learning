package main

import (
	"fmt"
	"math"
)

type Rectangle struct {
	width, length float64
}

type Circle struct {
	radius float64
}

// 继承方法
type Cuboid struct {
	Rectangle
	heught float64
}

func (r Rectangle) area() float64 {
	return r.width * r.length
}

func (c Circle) area() float64 {
	return c.radius * c.radius * math.Pi
}


func main() {
	r := Rectangle{5,5}
	c := Circle{5}
	cu := Cuboid{Rectangle{5,5},6}

	fmt.Println("rectangle area:", r.area())
	fmt.Println("circle area:", c.area())
	fmt.Println("cube area:", cu.area())
}
