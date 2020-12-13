package main

import "fmt"

const (
	WHITE = iota
	BLACK
	BLUE
	RED
	YELLOW
)

// Box some coment
type Box struct {
	width, height, depth float64
	color                Color
}

// Color some comment
type Color byte

// BoxList some comment
type BoxList []Box // a slice of boxes

// Volume some comment
func (b Box) Volume() float64 {
	return b.width * b.height * b.depth
}

// SetColor some comment
func (b Box) SetColor(c Color) {
	b.color = c
}

// BiggestColor some comment
func (b1 BoxList) BiggestsColor() Color {
	v := 0.00
	k := Color(WHITE)
	for _, b := range b1 {
		if b.Volume() > v {
			v = b.Volume()
			k = b.color
		}
	}
	return k
}

// PaintItBlack some comment
func (b1 BoxList) PaintItBlack() {
	for i := range b1 {
		b1[i].SetColor(BLACK)
	}
}

// String
func (c Color) String() string {
	strings := []string{"WHITE", "BLACK", "BLUE", "RED", "YELLOW"}
	return strings[c]
}

func main() {
	boxes := BoxList{
		Box{4, 4, 4, RED},
		Box{10, 10, 1, YELLOW},
		Box{1, 1, 20, BLACK},
		Box{10, 10, 1, BLUE},
		Box{10, 30, 1, WHITE},
		Box{20, 20, 20, YELLOW},
	}
	fmt.Printf("We have %d boxes in our set\n", len(boxes))
	fmt.Println("The volume of the first one is", boxes[0].Volume(), "cm3")
	fmt.Println("The color of the last one is", boxes[len(boxes)-1].color.String())
	fmt.Println("The biggest one is", boxes.BiggestsColor().String())
	// Let's paint them all black
	boxes.PaintItBlack()
	fmt.Println("The color of the second one is", boxes[1].color.String())
	fmt.Println("Obviously, now, the biggest one is", boxes.BiggestsColor().String())
}
