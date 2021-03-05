package main

import (
	"fmt"
	"math/rand"
	"regexp"
	"time"
)

/**
 * 1. 基本switch用法
 * 2. 调用函数
 * 3. 省略条件
 */

func main() {
	f1()
	f2()
	f3()

}

// 1. 基本switch用法
func f1() {
	fmt.Println("f1:")
	var i int
	fmt.Scanln(&i)

	// 可是所有基础类型，包括字符串
	// 多表达式以 ',' 分隔
	// 每条case默认以break结尾
	switch i {
	case 1:
		fmt.Println("input: 1")
	case 2:
		fmt.Println("input: 2")
	case 3, 4:
		fmt.Println("input greater than 2")
		fallthrough
	default:
		fmt.Println("other cases")
	}
}

// 2. 调用函数
func f2() {
	fmt.Println("f2")
	// switch 调用
	switch time.Now().Weekday().String() {
	case "Monday", "Tuesday", "Wednesday", "Thursday", "Friday":
		fmt.Println("It's time to learn some Go.")
	default:
		fmt.Println("It's weekend, time to rest!")
	}

	fmt.Println(time.Now().Weekday().String())

	// case 调用
	var email = regexp.MustCompile(`^[^@]+@[^@.]+\.[^@.]+`)
	var phone = regexp.MustCompile(`^[(]?[0-9][0-9][0-9][). \-]*[0-9][0-9][0-9][.\-]?[0-9][0-9][0-9][0-9]`)

	contact := "foo@bar.com"

	switch {
	case email.MatchString(contact):
		fmt.Println(contact, "is an email")
	case phone.MatchString(contact):
		fmt.Println(contact, "is a phone number")
	default:
		fmt.Println(contact, "is not recognized")
	}
}

// 省略条件
func f3() {
	fmt.Println("f3")
	rand.Seed(time.Now().Unix())
	r := rand.Float64()
	fmt.Println(r)
	switch {
	case r > 0.1:
		fmt.Println("Common case, 90% of the time")
	default:
		fmt.Println("10% of the time")
	}
}
