pub mod hello;

#[allow(unused_imports)]
use std::os::raw::c_char;
#[allow(unused_imports)]
use std::ffi::CStr;
#[allow(unused_imports)]
use crate::hello::hello_user;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn hello_user_test() {
        let name = "mortal\0".as_ptr() as *const c_char;
        hello_user(name);
    }
}
