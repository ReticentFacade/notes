package main

import (
	"context"
	"fmt"
)

func doSomething1(ctx context.Context) {
	fmt.Println("Doing something...")
	fmt.Println("ctx:", ctx)
}

func main1() {
	ctx := context.TODO() // creates an empty string (`string` ~= `context` here) that can be used as a placeholder

	doSomething1(ctx)
	fmt.Println("Did something")
}
