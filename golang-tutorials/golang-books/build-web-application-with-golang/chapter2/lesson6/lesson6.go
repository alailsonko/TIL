package main

import (
	"fmt"
	"strconv"
)

type Human struct {
	name  string
	age   int
	phone string
}

// String - Human implements fmt.Stringer
func (h Human) String() string {
	return "Name:" + h.name + ", age:" + strconv.Itoa(h.age) + " years, contact:" + h.phone
}

func main() {
	Bob := Human{"Bob", 39, "99999999999"}
	fmt.Println("This Human is :", Bob)
}
