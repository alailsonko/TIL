package main

import (
	"fmt"
	"microservices-with-go/sdk/client"
	"microservices-with-go/sdk/client/products"
	"testing"
)

func TestOurClient(t *testing.T) {
	cfg := client.DefaultTransportConfig().WithHost("localhost:9090")
	c := client.NewHTTPClientWithConfig(nil, cfg)
	// c := client.Default
	params := products.NewListProductsParams()

	prod, err := c.Products.ListProducts(params)
	if err != nil {
		t.Fatal(err)
	}
	fmt.Println(prod)
}
