package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

func numbers(s string) int {
	var n int
	i, err := strconv.Atoi(s)
	if err == nil {
		n = i
	}
	return n
}

func square(n int) string {
	var squareArray []string
	for i := 0; i < n; i++ {
		var array []string
		for j := 0; j < n; j++ {
			array = append(array, "* ")
		}
		array = append(array, "\n")
		squareArray = append(squareArray, array...)
	}
	myString := strings.Join(squareArray, "")

	return myString
}

func main() {
	var firstLine int
	scanner := bufio.NewScanner(os.Stdin)
	for i := 1; i <= 1 && scanner.Scan(); i++ {
		switch i {
		case 1:
			firstLine = numbers(scanner.Text())
		}
	}
	start := time.Now()
	fmt.Println(square(firstLine))
	fmt.Println("benchmark:", time.Since(start))
	fmt.Println("tamanho da base", firstLine)
}
