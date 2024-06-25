## virtual functions 
- general size of a class is 1 byte
- size of class with virtual function is 8 byte .
- vptr gets created when we create a instance of class.
- vptr gets destruct at destructor prolog.
- when we create an object of a class with virtual function, then compiler adds a hidden member to the object known as vptr.
- This vptr points to a table called the virtual function table (vtable), which contains pointers to the virtual functions of the class.
- first vptr is defined in stack , then the class members.
- vtable is static array of function pointer.
- By casting the address of obj2 to a long*, the code attempts to access the memory location where the vptr of obj2 is stored.
- *vptr: This dereferences the pointer vptr , and give us the value stored in the vptr, which is the address of the vtable.
- So, in code below , 'vtable' will store the address of vtable.
- vtable[0] will contains the first virtual function address .
- we typecast it to function pointer and store it in 'fp' , whenever call fp() virtual fun will be called.
```cpp
int main()
	{
		using FPTR = void(*)();
		CC obj2; //Assume a class CC
		//step 1 reach the vptr
		long* vptr = (long*)&obj2;
		//step 2 reach the vtable
		long* vtable = (long*)*vptr;
		//step 3 reach the function
		// void(*fp)() = (void(*)())vtable[0];  //this also works
		FPTR fp=(FPTR)vtable[0];
		fp(); // calls the virtual function
		return 0;
	}

```
- virtual function interpretation by compiler  
using pointer : `objPtr->f2();//objPtr->vptr->vtable[0]();`  
using reference : `objRef.f2();//objRef.vptr->vtable[0]();`

- whenever virtual functions called from constructor or destructor ,then constructor/destructor class function will get called.
