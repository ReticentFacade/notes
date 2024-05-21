extern crate libc;
use std::ffi::CStr;

#[no_mangle]
pub extern "C" fn hello(name: *const libc::c_char) {
    let name_cstr = unsafe { CStr::from_ptr(name).to_bytes() };
    let name =String::from_utf8(name_cstr.to_vec()).unwrap();
    println!("Hello, {}!", name);
}

#[no_mangle] 
pub extern "C" fn yell(message: *const libc::c_char) {
    let message_cstr = unsafe { CStr::from_ptr(message)};
    let message = message_cstr.to_str().unwrap();
    println!("HELLO, {}!", message);
}

#[cfg(test)]
pub mod test {
    use std::ffi::CString;
    use super::*;

    #[test]
    fn simulated_main_function() {
        hello(CString::new("world").unwrap().into_raw());
        yell(CString::new("FROM THE OUTSIDEEEEE").unwrap().into_raw());
    }
}