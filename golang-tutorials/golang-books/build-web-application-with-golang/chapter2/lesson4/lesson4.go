package main

import "fmt"

// Human some comment
type Human struct {
	name  string
	age   int
	phone string
}

// Student some comment
type Student struct {
	Human
	school string
}

// Employee some comment
type Employee struct {
	Human
	company string
}

// SayHi some commment
func (h *Human) SayHi() {
	fmt.Printf("Hi, I am %s you can call me on %s\n", h.name, h.phone)
}

func main() {
	sam := Employee{Human{"sam", 45, "111-8888-xxxxx"}, "golang inc"}
	mark := Employee{Human{"mark", 25, "111-8888-xxxxx"}, "MIT"}

	sam.SayHi()
	mark.SayHi()
}
