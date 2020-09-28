// package main

// import (
// 	"fmt"
// )

// func main() {
// 	fmt.Println("start")
// 	panicker()
// 	fmt.Println("end")
// }

// // func panicker() {

// // fmt.Println("about the panic")
// // defer func() {
// // 	if err := recover(); err != nil {
// // 		log.Println("Error:", err)
// // 	}
// // }()
// // panic("something bad happened")
// // fmt.Println("done panicking")
// // }

// // func main() {

// // fmt.Println("start")
// // defer fmt.Println("")

// // http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
// // 	w.Write([]byte("hello go"))
// // })
// // err := http.ListenAndServe(":8080", nil)
// // if err != nil {
// // 	panic(err.Error())
// // }

// // a, b := 1, 0
// // ans := a / b
// // fmt.Println(ans)

// // a := "start"
// // defer fmt.Println(a)
// // a = "end"

// // res, err := http.Get("https://www.github.com/alailsonko")
// // if err != nil {
// // 	log.Fatal(err)
// // }
// // robots, err := ioutil.ReadAll(res.Body)
// // res.Body.Close()
// // if err != nil {
// // 	log.Fatal(err)
// // }
// // fmt.Printf("%s", robots)
// // }
