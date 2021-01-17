package main

import "fmt"

// Structs defines state. Structs hold only state and no behavior
type Creature struct {
	Name string
	Real bool
}

// Methods are functions that operate on particular types.
// they have a receiver clause that mandates what type they operate on.
func (c Creature) Dump() {
	fmt.Printf("Name: %s, Real: %t\n", c.Name, c.Real)
}

// Emdedding you can embed anonymous types inside each other.
// if you embed a nameles struct then the embedded struct
// provides its state (and methods) to the embedding struct directly.
type FlyingCreature struct {
	Creature
	WingSpan int
}

// Interfaces are types that declare sets of methods.
type Fooer interface {
	Foo1()
	Foo2()
	Foo3()
}

type foo struct {
}

func (f foo) Foo1() {
	fmt.Println("Foo1() here")
}
func (f foo) Foo2() {
	fmt.Println("Foo2() here")
}
func (f foo) Foo3() {
	fmt.Println("Foo3() here")
}

func NewFoo() Fooer {
	return &foo{}
}

func main() {
	dragon := &FlyingCreature{
		Creature{"Dragon", false},
		15,
	}
	f := NewFoo()

	f.Foo1()
	f.Foo2()
	f.Foo3()

	fmt.Println(dragon.Name)
	fmt.Println(dragon.Real)
	fmt.Println(dragon.WingSpan)
	dragon.Dump()
}
