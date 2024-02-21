#[allow(unused_imports)]
use std::os::raw::c_char;
use std::ffi::CStr;

pub enum CResult {
    Ok, 
    Err,
}

#[no_mangle]
pub extern "C" fn hello_user(name: *const c_char) {
    let name_str = unsafe {
        CStr::from_ptr(name)
    };

    if let Ok(name) = name_str.to_str() {
        println!("Hello, {}!", name);
    } else {
        eprintln!("Invalid UTF-8 string");
    }
}