package main

import (
	"building-microservices/product-api/sdk/client"
	"building-microservices/product-api/sdk/client/products"
	"fmt"
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
