package main

// #cgo CFLAGS: -I./lib
// #cgo LDFLAGS: -L./lib/hello/target/release -lhello
// #include "hello.h"
import "C"

func main() {
	C.hello(C.CString("world"))
	C.yell(C.CString("YOU!"))
}
