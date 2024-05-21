package main

import (
	"context"
	"fmt"
)

func doSomething2(ctx context.Context) {
	fmt.Println("doSomething2: myKey's value is: ", ctx.Value("myKey"))
}

func main() {
	ctx := context.Background()

	ctx = context.WithValue(ctx, "myKey", "myValue")

	doSomething2(ctx)
	fmt.Println("Did something")
}
