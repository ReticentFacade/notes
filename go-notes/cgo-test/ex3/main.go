package main

// #cgo LDFLAGS: -L. -lhello.dylib
// #include "libhello.dylib"
import "C"

func rustFileOperation() {
	C.hello()
}

func main() {
	rustFileOperation()
	// Call gRPC functions to communicate with the Go web server here
}
