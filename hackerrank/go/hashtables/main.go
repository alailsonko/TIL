package main

import (
	"fmt"
	"github.com/cheekybits/genny/generic"
	"sync"
)

// Key the key of the dicionary
type Key generic.Type

// Value the content of the dictionary
type Value generic.Type

// ValueHashtable the set of Items
type ValueHashtable struct {
	items map[int]Value
	lock  sync.RWMutex
}

// the hash() private function uses the famous Horners method
// to generate a hash of a string with O(n) complexity
func hash(k Key) int {
	key := fmt.Sprintf("%s", k)

	h := 0

	for i := 0; i < len(key); i++ {
		h = 31*h + int(key[i])
	}
	return h
}

// put item with value v and key k into the hashtable
func (ht *ValueHashtable) Put(k Key, v Value) {
	ht.lock.Lock()
	defer ht.lock.Unlock()

	i := hash(k)

	if ht.items == nil {
		ht.items = make(map[int]Value)
	}
	ht.items[i] = v
}

func main() {
	fmt.Println("vim-go")
}
