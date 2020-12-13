package main

import (
	"errors"
	"fmt"
	"math"
	"os"
)

func main() {

	// -------------- variable -----------------
	// single variable
	var name string
	// multiple variable
	var firstName, lastName string

	name = "alailson"
	firstName = "alailson"
	lastName = "andrade"

	// with type
	// var address, number, state string = "street herculandia", "5000", "some state"

	// without type
	// var address, number, state = "street herculandia", "5000", "some state"

	// another way to declare variable
	address, number, state := "street herculandia", "5000", "some state"

	fmt.Println("name:", name)
	fmt.Println("fullname:", firstName, lastName)
	fmt.Println("address:", address, "number:", number, "state:", state)

	// -------------- constants --------------------------------
	const Pi float32 = 3.1415926
	const i = 10000
	const MaxThread = 10
	const prefix = "alailson"
	fmt.Println("my constants", Pi, "\n", i, "\n", MaxThread, "\n", prefix)

	// ----------- elementary type  ----------------
	test() // calls the function
	control()
}

// sample code
var isActive bool                   // global variable
var enabled, disabled = true, false // omit type of variables

var frenchHello string
var emptyString string = ""

// ------- elementary type ------------
func test() {
	// --- boolean -----
	var available bool // local variable
	valid := false     // brief statement of variable
	available = true   // assign value of variable

	fmt.Printf("booolean")
	fmt.Println(available)
	fmt.Println(valid)
	fmt.Println(isActive)
	fmt.Println(enabled)
	fmt.Println(disabled)

	//---------- numerical types --------
	// rune, int8, int 32, int 64, byte,
	// unint8, unint16, uint32, uint64
	// rune is an alias of int32
	// byte is an alias of int8
	// u can not assign values between these type
	//example code
	// var a int8
	// var b int32
	// c := a + b
	// float32, float64
	// complex128 >> real 64-bit and mi 64-bit
	// complex64 >> real 32-bit and mi 32-bit
	var c complex64 = 5 + 5i
	fmt.Printf("value is: %v", c)

	// ---------- string ------------
	no, yes, maybe := "no", "yes", "maybe"
	japaneseHello := "ohaiou"
	frenchHello = "Bonjour"
	fmt.Println(no)
	fmt.Println(yes)
	fmt.Println(maybe)
	fmt.Println(japaneseHello)
	fmt.Println(frenchHello)

	// change one character
	myString := "hello"
	convert := []byte(myString) // convert string to []byte type
	convert[0] = 'c'
	s2 := string(convert) // convert back to string type
	fmt.Printf("%s\n", s2)
	fmt.Println("converted", s2)
	myString = "C" + myString[1:]
	fmt.Printf("%s\n", myString)
	fmt.Println("converted", myString)
	m := `
	   hello
       world
	`
	fmt.Println("string multiple line:", m)

	// ------- Error types ------------
	err := errors.New("emit one new error")
	if err != nil {
		fmt.Print(err)
		fmt.Println("error")
	}
	// --------- bonus skill -----
	// ------- basic form
	// import fmt
	// import os
	// const i = 100
	// const i = 100
	// const i = 100
	// const i = 100
	// var i int
	// var i int
	// var i int
	// ------- group form
	// import (
	//     fmt
	//           os
	//              )
	// const ( i = 100
	//   i = 100
	//   i = 100
	//    i = 100 )
	// var ( i int
	//   i int
	//   i int )

	// ------------- iota enumerate ---------
	const (
		x = iota // x == 0
		y = iota // y == 1
		z = iota // z == 2
		w        // if there is not expression after the constants name,
		// it use the last expression
		// so its saying w = iota implicitly. w == 3

	)

	const v = iota

	const (
		e, f, g = iota, iota, iota
	)

	// ---------------  array slice map ---------
	// --- array
	var arr [10]int // an array of type [10]int
	arr[0] = 42     // an array is 0-based
	arr[1] = 13     // assign value to element
	fmt.Printf("the first element is %d\n", arr[0])
	// get element value, it returns 42
	fmt.Printf("the last element is %d\n", arr[9])
	fmt.Println("arrays", arr)
	a := [3]int{1, 2, 3}
	// define and int array with 3 elements
	b := [10]int{1, 2, 3}
	// define a int array with 10 elments,
	// of which first 3 are defined
	ccc := [...]int{4, 5, 6}
	// use ... to replace the length parameters
	// go will calculate for u
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(ccc)
	// define a two-dimensional array with 2 elements,
	// and each element has 4 elements
	doubleArray := [2][4]int{[4]int{1, 2, 3, 4}, [4]int{5, 6, 7, 8}}
	fmt.Println(doubleArray)
	easyArray := [2][4]int{{1, 2, 3, 4}, {5, 6, 7, 8}}
	fmt.Println(easyArray)
	// --- slice
	// slice does not need length
	slice := []byte{'a', 'b', 'c', 'd'}
	fmt.Println(slice)
	// define an array with 10 elements whose types are bytes
	var ar = [10]byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}
	fmt.Println(ar)
	// define two slices with type []byte
	var aa, bb []byte
	fmt.Println("a:", aa, "b:", bb)
	// 'a' points to elements from 3rd to 5th in array ar
	aa = ar[2:5]
	// now 'a' has elements ar[2], ar[3] and ar[4]
	// 'b' is another slice of array ar
	bb = ar[3:5]
	fmt.Println("a:", aa, "b:", bb)
	// define an array
	var arrayArr = [10]byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}
	fmt.Println(arrayArr)
	// define two slices
	var aSlice, bSlice []byte
	fmt.Println(bSlice)

	// some convenient operations
	aSlice = arrayArr[:3]
	aSlice = arrayArr[5:]
	aSlice = arrayArr[:]

	// slice from slice
	aSlice = arrayArr[3:7]
	bSlice = aSlice[1:3]
	bSlice = aSlice[:3]
	bSlice = aSlice[0:5]
	bSlice = aSlice[:]

	// ---------- map
	// use string as the key type, int as the value type and make
	// initialize it
	// var numbers map[string]int
	// another way to define map
	numbers := make(map[string]int)
	numbers["one"] = 1
	numbers["nte"] = 10
	numbers["three"] = 3

	fmt.Println("the third number is: ", numbers["three"]) // get values
	// it prints: the third number is: 3

	// initialize a map
	rating := map[string]float32{"C": 5, "Go": 4.5, "Python": 4.5, "C++": 5}
	// map has two return values. for the second return value, if the key value
	// does not exist 'ok' returns false. it returns true otherwise
	csharpRating, ok := rating["C#"]
	if ok {
		fmt.Println("C# is in the map an its rating is ", csharpRating)
	} else {
		fmt.Println("We have no rating associated with c# in the map")
	}

	delete(rating, "C") // delete element with key "C"

	fmt.Println(rating)
	fmt.Println(csharpRating)

	mm := make(map[string]string)
	mm["hello"] = "Bonjour"
	m1 := mm
	m1["hello"] = "salut"
	fmt.Println(m1, m)

	// --------- make , new

}

func computedValue() int {
	return 9
}

func control() {
	// --------- contrl statement ------
	// ---- if/else
	x := 11

	if x > 10 {

		fmt.Println("x is greater than 10")
	} else {

		fmt.Println("x is less than or equal to 10")
	}
	// --- initialize x, then check if x greater than
	if xx := computedValue(); xx > 10 {
		fmt.Println("x is greater than 10")
	} else {
		fmt.Println("x is less than 10")
	}
	// the following code will not compile
	// fmt.Println(xx)

	// ---- multiple conditions
	integer := 3
	if integer == 3 {
		fmt.Println("the integer is equal to 3")
	} else if integer < 3 {
		fmt.Println("the integer is less than 3")
	} else {
		fmt.Println("the integer is greater than 3")
	}
	// --- goto
	// myFunc()
	sum := 0
	for index := 0; index < 10; index++ {
		sum += index
	}
	for sum < 1000 {
		sum += sum
	}
	for index := 10; index > 0; index-- {
		if index == 5 {
			break // or continue
		}
		fmt.Println(index)
	}
	fmt.Println("sum is equal to ", sum)

	// for k,v := range map {
	// 	fmt.Println("maps key:", k)
	// 	fmt.Println("maps val:", v)
	// }

	//----------- switch ---------
	i := 10
	switch i {
	case 1:
		fmt.Println("i is equal to 1")
	case 2, 3, 4:
		fmt.Println("i is equal to 2,3 or 4")
	case 10:
		fmt.Println("i is equal to 10")
	default:
		fmt.Println("All i know is that i is an integer")
	}
	intI := 6
	switch intI {
	case 4:
		fmt.Println("integer <= 4")
		fallthrough
	case 5:
		fmt.Println("integer <= 5")
		fallthrough
	case 6:
		fmt.Println("integer <= 6")
		fallthrough
	case 7:
		fmt.Println("integer <= 7")
		fallthrough
	case 8:
		fmt.Println("integer <= 8")
		fallthrough
	default:
		fmt.Println("default case")
	}

	// ---- functions ------------
	fmt.Println(max(5, 7))
	fmt.Println(SumAndProduct(10, 14))
	xxx := 3
	fmt.Println("x = ", x) // should print "x = 3"

	x1 := add1(xxx) // call add1(x)

	fmt.Println("x + 1 = ", x1) // should print "x+1" = 4
	fmt.Println("x = ", x)      // should print "x = 3"
	fmt.Println("x = ", x)
	x2 := add2(&x) // call add2(&x) pass memory address of x

	fmt.Println("x+1 = ", x2)
	fmt.Println("x = ", x)

	// ---- defer
	// for i := 0; i < 5; i++ {
	// 	fmt.Println("--------------", i)
	// 	defer fmt.Printf("%d ", i)
	// 	defer fmt.Println("--------------", i)
	// }

	// ------ functions as values and types
	var slice = []int{1, 2, 3, 4, 5, 7}

	odd := filter(slice, isOdd)
	even := filter(slice, isEven)

	fmt.Println(odd)
	fmt.Println(even)
	fmt.Println("even")

	// -------- Panic and Recover --------

	initt()

	// --------- struct ------
	type person struct {
		name string
		age  int
	}

	var P person

	P.name = "alailson"
	P.age = 22
	fmt.Printf("the person name is %s\n", P.name)

	P1 := person{age: 22, name: "alailson"}
	fmt.Printf("name %s\n", P1.name)

	P2 := struct {
		name string
		age  int
	}{"alailson", 22}
	fmt.Printf("name %s\n", P2.name)

	var tom person11

	tom.name, tom.age = "tom", 18
	bob := person11{age: 25, name: "Bob"}
	paul := person11{"Paul", 43}

	tbOlder, tbdiff := older(tom, bob)
	tpOlder, tpdiff := older(paul, paul)
	ttOlder, ttdiff := older(paul, bob)
	fmt.Println(tbOlder, tbdiff, tpOlder, tpdiff, ttOlder, ttdiff)
	fmt.Printf("%s %s %s", tom.name, bob.name, paul.name)

	// -------- object oriented
	r1 := Rectangle{12, 2}
	r2 := Rectangle{9, 4}
	fmt.Println("area of r1 is:", area(r1))
	fmt.Println("area of r2 is:", area(r2))

	c1 := Circle{10}
	c2 := Circle{25}
	r11 := Rect{9, 4}
	r22 := Rect{12, 2}

	fmt.Println(c1.Area())
	fmt.Println(c2.Area())
	fmt.Println(r11.Area())
	fmt.Println(r22.Area())

}

// Circle daoijda
type Circle struct {
	radius float64
}

// Rect daoijda
type Rect struct {
	width, height float64
}

// Area daoijda
func (c Circle) Area() float64 {
	return c.radius * c.radius * math.Pi
}

// Area daoijda
func (r Rect) Area() float64 {
	return r.width * r.height
}

// Rectangle diaoijda
type Rectangle struct {
	width, height float64
}

func area(r Rectangle) float64 {
	return r.width * r.height
}

type person11 struct {
	name string
	age  int
}

// Older duhaiudhsa
func older(p1, p2 person11) (person11, int) {
	if p1.age > p2.age {
		return p1, p1.age - p2.age
	}
	return p2, p2.age - p1.age
}

var user = os.Getenv("USER")

func initt() {

	if user == "" {
		panic("no value for $USER")
	}
}

// ----------------------------------------------------------------
type testInt func(int) bool // define a function type of variable

func isOdd(intII int) bool {
	return intII%2 != 0
}
func isEven(intII int) bool {
	return intII%2 == 0
}

func filter(slice []int, f testInt) []int {
	var result []int
	for _, value := range slice {
		if f(value) {
			result = append(result, value)
		}
	}
	return result
}

// ----------------------------------------------------------------

func add2(a *int) int {
	*a = *a + 1
	return *a
}

// simple function to add 1 to a
func add1(a int) int {
	a = a + 1
	return a
}

// SumAndProduct make the sum and the product
func SumAndProduct(A, B int) (int, int) {
	return A + B, A * B
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func myFunc() {
	i := 0
Here:
	fmt.Println(i)
	i++
	goto Here
}
