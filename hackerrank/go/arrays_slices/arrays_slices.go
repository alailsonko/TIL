package main

import "fmt"

// ## array
// An array in Go is a data structure that consists of an ordered sequence
// of elements that has its capacity defined at creation time.
// Once an array has allocated its size, the size can no longer be changed.

// ## slice
// A slice, on the other hand, is a variable length version of an array, providing
// more flexibility for developers using these data structures. Slices constitute
// what you would think of as arrays in other languages.

func main() {
	var numbers [3]int
	fmt.Println(numbers)

	coral := [4]string{"blue coral", "staghorn coral", "pillar coral", "elhorn coral"}
	// coral = append(coral, "black coral")
	fmt.Println(coral)

	seaCreatures := []string{"shark", "cuttlefish", "squid", "mantis shrimp", "anemone"}
	fmt.Println(seaCreatures)

	oceans := make([]string, 3)
	fmt.Println(oceans)

	fmt.Println(coral[1:3])

	// converting from an array to a slice
	coralSlice := coral[:]

	coralSlice = append(coralSlice, "black coral")
	fmt.Println(coralSlice)

	coralSlice = append(coralSlice, "antipaths", "leptosmania")

	fmt.Println(coralSlice)

	moreCoral := []string{"massive coral", "soft coral"}

	coralSlice = append(coralSlice, moreCoral...)

	fmt.Println(coralSlice)
	// removing an element from a slice
	coralSlice = []string{"blue coral", "foliose coral", "pillar coral", "elhorn coral", "black coral"}
	coralSlice = append(coralSlice[:3], coralSlice[4:]...)
	fmt.Println(coralSlice)

	coralSlice = []string{"blue coral", "foliose coral", "pillar coral", "elkohn coral", "black coral", "antipathes", "leptopsamia", "massive coral", "soft coral"}
	coralSlice = append(coralSlice[:3], coralSlice[6:]...)
	fmt.Println(coralSlice)

	// Measuring the capacity of a slice with cap()

	num := []int{}

	for i := 0; i < 100000; i++ {
		num = append(num, i)
	}
	fmt.Println(num)

	numrs := make([]int, 100000)
	for i := 0; i < cap(numrs); i++ {
		numrs[i] = i
	}

	fmt.Println(numrs)

	// Constructing Multidimensional Slices
	seaNames := [][]string{{"shark", "octopus", "squid", "mantis schrimp"}, {"Sammy", "jeese", "othername", "lastname"}}
	fmt.Println(seaNames[1][0])
	fmt.Println(seaNames[0][0])

	seaNames[0][0] = "lion"
	seaNames[0][1] = "apey"
	seaNames[0][2] = "snake"
	seaNames[0][3] = "turtle"

	seaNames[1][0] = "ox"
	seaNames[1][1] = "fish"
	seaNames[1][2] = "gorilla"
	seaNames[1][3] = "lion"

	fmt.Println(seaNames)
}
