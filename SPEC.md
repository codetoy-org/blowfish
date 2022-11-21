# Language spec proposals

## ASM's ideal spec
```
//Comment

//Lines end with ;

//Scopes are defined with {}

//Optional static typing
let duckTyped = 0; //Defaults to i32
let staticTyped: i32 = 0;

//Primitive types
/* i8, u8, i16, u16, i32, u32, i64, u64, i128, u128, i256, u256 */

//Functions also have optional static types
def myFunc(text: string, duckTyped) {
	if(duckTyped is string) {
		//Print here is sourced from the application, and its just a call to printf.
		//The application can automatically turn 'text' into the appropriate char* for printf
		print("Cool! %s and %s", text, duckTyped);
	} else {
		print("Idk the type :( %s", text);
	}
}
//Function with static return type
def checkStr(text: string): u8 {
	if(text == "true") {
		return true;
	}
	return false;
}

//Class types come from runtime (the application embedding blowfish)

//Struct types
struct myStruct {
	someBool: u8;
	someString: string;
	duckTyped = "Must be initialized here";

	def myStruct() {
		someBool = true;
		someString = "I will not be empty now";
	}

	def getDucked() {
		return this.duckTyped;
	}
}

//Pointer types are created with the 'ptr' keyword and dereferenced with the 'drf' keyword
//C++ equivelant: i32 myVal = 5;
let myVal: i32 = 5;
//C++ equivelant: i32* myPtr = &myVal;
let myPtr: ptr->i32 = ptr myVal;
//C++ equivelant: i32 myInt = *myPtr;
let myInt: i32 = drf myVal;
//myInt would be 5

//Pointers are also type optional, but not like duck types (they can be truely typeless)
//C++ equivelant: int myVal = 46;
let myVal: i32 = 46;
//C++ equivelant: void* myPtr = (void*)&myVal;
let myPtr: ptr = ptr myVal;
//C++ equivelant: char[] myBytes = (char[])(*myPtr);
let myBytes: u8[] = drf myPtr;

//We can also rewrite parts of the script itself at runtime with hacky stuff like this
//C++ equivelant (not possible bc diff heaps): char[] = (char[])&69420;
let myBytes: u8[] = drf ptr->i32 69420;
//This would actually change the 69420 number that is 'hard-coded' in the script, but its technically on the
//heap inside of the interpreter's memory, and as such it can be changed.
```