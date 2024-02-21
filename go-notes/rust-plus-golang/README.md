# Rust-Plus-GoLang
Integration between Rust and Go by calling a Rust library (wrapped in a C-lib) from a Go program.

## Structure: 
```
➜  rust-plus-golang git:(master) ✗ tree -I target
.
├── Taskfile.yml
├── go.mod
├── lib
│   ├── hello
│   │   ├── Cargo.lock
│   │   ├── Cargo.toml
│   │   └── src
│   │       └── lib.rs
│   └── hello.h
└── main_dynamic.go

4 directories, 7 files
```

## 
### Rust Code (./lib/hello/src/lib.rs)
Since `cgo` is being used, Rust functions take C-strings as input.
- `fn hello(name: *const libc::c_char)`
- `fn yell(message: *const libc::c_char)`
  
* To build the library, use: 
```
✗ cd lib/hello
✗ cargo build --release --lib
```

### C-Wrapper (./lib/hello.h)
- Wraps the functions defined in the Rust-section.

### Go Code (./main_dynamic.go)
- Uses the wrapped functions from the C-wrapper-library `(./lib/hello.h)`

- Use `cgo` in `main_dynamic.go` by adding this at the top of the file: 
```
// #cgo CFLAGS: -I<path-to-dir>/rust-plus-golang/lib
// #cgo LDFLAGS: -L<path-to-dir>/rust-plus-golang/lib/hello/target/release -lhello
// #include "hello.h"
import "C"
```

- Build it using: 
```
go build -ldflags="-L./lib/hello/target/release -lhello"
```

- Run using:
```
./main_dynamic
```