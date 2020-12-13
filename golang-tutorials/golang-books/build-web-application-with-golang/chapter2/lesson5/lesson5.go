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
	loan   float32
}

// Employee some content
type Employee struct {
	Human
	company string
	money   float32
}

// Men Interface Men implemented by human, Student and Employee
type Men interface {
	SayHi()
	Sing(lyrics string)
}

// SayHi some comment
func (h Human) SayHi() {
	fmt.Printf("Hi, i am %s u can call me on %s\n", h.name, h.phone)
}

// Sing some comment
func (h Human) Sing(lyrics string) {
	fmt.Println("La lalalla...", lyrics)
}

// SayHi some comment
func (e Employee) SayHi() {
	fmt.Printf("Hi, I am %s, I work at %s. call me on %s\n", e.name,
		e.company, e.phone)
}

func main() {
	mike := Student{Human{"mike", 25, "22222222"}, "mit", 0.00}
	paul := Student{Human{"paul", 26, "22222222"}, "Harvard", 3.44}
	sam := Employee{Human{"sam", 36, "22222222"}, "Golang inc", 44.55}
	tom := Employee{Human{"sam", 36, "22222222"}, "things ltd", 56.44}

	// define interface i
	var i Men

	// i can store Student
	i = mike
	fmt.Println("this is mike, a student")
	i.SayHi()
	i.Sing("november rain")

	// i can store Employee
	i = tom
	fmt.Println("this is tom, an employee")
	i.SayHi()

	i.Sing("born to be wild")

	// slice of men
	fmt.Println("Lets use a slice of men and see what hapens")
	x := make([]Men, 3)
	// these three elements are different types but they all implements
	x[0], x[1], x[2] = paul, sam, mike
	for _, value := range x {
		value.SayHi()
	}
}
