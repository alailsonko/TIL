package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func main() {

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		log.Println("hello world")
		d, err := ioutil.ReadAll(r.Body)

		if err != nil {
			http.Error(w, "Oooops", http.StatusBadRequest)
			return
		}

		log.Printf("Data %s\n", d)

		fmt.Fprintf(w, "Hello %s\n", d)
	})

	http.HandleFunc("/goodbye", func(http.ResponseWriter, *http.Request) {
		log.Println("goodbye router")
	})

	http.ListenAndServe(":9090", nil)
}
