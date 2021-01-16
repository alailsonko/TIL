package main

import (
	"fmt"
	"sort"
)

func main() {

	// Understanding Maps in Go

	sammy := map[string]string{"name": "sammy", "animal": "shark", "color": "blue", "location": "ocean"}

	fmt.Println(sammy["name"])

	for key, value := range sammy {
		fmt.Printf("%q is the key for the value %q\n", key, value)
	}

	keys := []string{}

	for key := range sammy {
		keys = append(keys, key)
	}
	sort.Strings(keys)
	fmt.Printf("%q\n", keys)

	sonko := map[string]string{"name": "sonko", "animal": "shark", "color": "blue", "location": "ocean"}

	items := make([]string, len(sonko))
	var i int
	for _, v := range sonko {
		items[i] = v
		i++
	}

	fmt.Printf("%q\n", items)

	// Checking existence

	counts := map[string]int{}

	if count, ok := counts["sammy"]; ok {
		fmt.Printf("Sammy has a count of %d\n", count)
	} else {
		fmt.Printf("Sammy was not found\n")
	}

	// Modifying Maps
	// Adding and Changing Map Items
	usernames := map[string]string{"sammy": "sammy-shark", "jamie": "mantissrimp"}

	usernames["Drew"] = "squidly"
	fmt.Println(usernames)

	usernames = map[string]string{"sammy": "sammy-shark", "jamie": "massnti"}

	permissions := map[int]string{1: "read", 2: "write", 4: "delete", 8: "create", 16: "modify"}

	delete(permissions, 16)

	fmt.Println(permissions)

}
