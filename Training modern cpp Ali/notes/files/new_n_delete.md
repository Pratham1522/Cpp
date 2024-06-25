## new and delete keyword working :
### new working :
- create a temporay pointer of class
- try constructor call of the object
- if any exception occurs or throw from constructor then catch and delete the object
- if no exception then assign temp to variable
```cpp
    //cat=new Cat() ; 
    cat *temp=operator new(1); //temp pointer
    try{
        temp->Cat::Cat(); //constructor call
    } catch(...)
    {
        operator delete(temp);
        throw;
    }
    cat=temp;
```
### new overloading
```cpp
    static void* operator new(size_t size)
    {
        cout<<"CAT operator NEW\n";
        return malloc(100);
    }
```

### delete working 
- call destructor
- call operator delete to free memory
```cpp
    // delete cat; 
    cat->Cat::~Cat();
    Cat::operator delete(cat);
```
### delete overloading
```cpp
    static void operator delete (void *pv)
    {
        cout<<"CAT operator DELETE \n";
        free(pv);
    }
```
### Infinite delete
```cpp
    ~CA()
    {
        cout<<"CA D-tor \n";
        delete this;   //infinite loop if this statement
    }
```
