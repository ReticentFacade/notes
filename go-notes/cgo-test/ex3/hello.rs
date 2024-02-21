use std::ffi::CStr;

#[no_mangle]
pub extern "C" fn hello() {
    println!("Hello, world!");
}