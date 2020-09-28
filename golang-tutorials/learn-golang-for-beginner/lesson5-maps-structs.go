// package main

// import "fmt"

// // func main() {
// // 	statePopulations := make(map[string]int)
// // 	statePopulations = map[string]int{
// // 		"California":   39250017,
// // 		"Texas":        27862596,
// // 		"Florida":      20612439,
// // 		"New York":     19745289,
// // 		"Pennsylvania": 12801539,
// // 		"Ohio":         11614373,
// // 	}
// // 	statePopulations["Georgia"] = 128712812

// // 	pop, ok := statePopulations["Ohio"]

// // 	sp := statePopulations
// // 	delete(sp, "Ohio")

// // 	fmt.Println(sp)
// // 	fmt.Println(statePopulations)

// // 	delete(statePopulations, "Georgia")
// // 	fmt.Println(statePopulations["Oho"])
// // 	fmt.Println(statePopulations)
// // 	fmt.Println(pop, ok)
// // 	fmt.Println(len(statePopulations))
// // // }

// // type Doctor struct {
// // 	// number     int
// // 	// actorName  string
// // 	// episodes   []string
// // 	// companions []string
// // }
// type Animal struct {
// 	Name   string
// 	Origin string
// }

// type Bird struct {
// 	Animal
// 	SpeedKPH float32
// 	CanFly   bool
// }

// func main() {
// 	b := Bird{
// 		Animal:   Animal{Name: "Emu", Origin: "Australia"},
// 		SpeedKPH: 48,
// 		CanFly:   false,
// 	}
// 	// b.Name = "Emu"
// 	// b.Origin = "Australia"
// 	// b.SpeedKPH = 48
// 	// b.CanFly = false
// 	fmt.Println(b.Animal.Name)

// 	// aDoctor := struct{ name string }{name: "John Pertwee"}
// 	// anotherDoctor := aDoctor
// 	// anotherDoctor.name = "Tom Baker"
// 	// fmt.Println(aDoctor)
// 	// fmt.Println(anotherDoctor)
// 	// aDoctor := struct{ name string }{name: "John Pertwee"}

// 	// aDoctor := Doctor{
// 	// 	number:    3,
// 	// 	actorName: "John Pertwee",
// 	// 	episodes:  []string{},
// 	// 	companions: []string{
// 	// 		"Liz Shaw",
// 	// 		"Jo Grant",
// 	// 		"Sarah Jane Smith",
// 	// 	},
// 	// }
// 	// fmt.Println(aDoctor)
// }
