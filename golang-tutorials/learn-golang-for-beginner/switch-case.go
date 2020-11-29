package main

import (
	"fmt"
	"time"
)

func main() {
	i := 2

	fmt.Println("Write ", i, " as ")
	switch i {
	case 1:
		fmt.Println("one")
	case 2:
		fmt.Println("two")
	case 3:
		fmt.Println("three")
	}

	switch time.Now().Weekday() {
	case time.Saturday, time.Sunday:
		fmt.Println("its the weekend")
	default:
		fmt.Println("its a weekday")
	}

	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("its before noon")
	default:
		fmt.Println("its after noon")
	}

	whatAmI := func(i interface{}) {
		switch t := i.(type) {
		case bool:
			fmt.Println("im a bool")
		case int:
			fmt.Println("im an int")
		default:
			fmt.Printf("dont know type %T\n", t)
		}
	}

	whatAmI(true)
	whatAmI(1)
	whatAmI("hey")
}
