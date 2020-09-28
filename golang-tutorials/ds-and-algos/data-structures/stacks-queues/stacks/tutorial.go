package main

import "fmt"

//Stack represents stacck that hold a slice
type Stack struct {
	items []int
}

// Push will add a value at the end
func (s *Stack) Push(i int) {
	// add
	s.items = append(s.items, i)
}

//Pop will remove a vale at the end
// and RETURNs the removed value
func (s *Stack) Pop() int {
	l := len(s.items) - 1
	toRemove := s.items[l]
	s.items = s.items[:l]
	return toRemove
}

func main() {
	myStack := Stack{}
	fmt.Println((myStack))
	myStack.Push(100)
	myStack.Push(200)
	myStack.Push(300)
	fmt.Println((myStack))
	myStack.Pop()
	fmt.Println((myStack))

}
