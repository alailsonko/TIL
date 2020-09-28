// package main

// import "fmt"

// func main() {
// 	var w Writer = ConsoleWriter{}
// 	w.Write([]byte("hello go"))
// }

// type Writer interface {
// 	Write([]byte) (int, error)
// }

// type ConsoleWriter struct{}

// func (cw ConsoleWriter) Write(data []byte) (int, error) {
// 	n, err := fmt.Println(string(data))
// 	return n, err
// }
