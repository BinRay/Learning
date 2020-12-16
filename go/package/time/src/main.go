package main

import (
	"fmt"
	"time"
)

func main() {
	ticker := time.NewTicker(time.Second)
	stopper := time.NewTimer(time.Second * 10)

	var i int
	for {
		select {
		case <-stopper.C:
			goto StopHere
		case <-ticker.C:
			i++
			fmt.Println("tick", i)
		}
	}

StopHere:
	fmt.Println("done")
}
