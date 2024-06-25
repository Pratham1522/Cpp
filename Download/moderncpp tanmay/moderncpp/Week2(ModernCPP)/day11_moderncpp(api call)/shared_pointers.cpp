/* #include <iostream>
#include <vector>

class shared_pointers
{
private:
    int Id;
    std::vector<int> _readings;
    int *_extra_values;
    int _N;

public:
    shared_pointers(int id, std::vector<int> &&readings, int *base, int n)
        : Id(id), _readings(readings), _N(n)
    {
        int *_extra_values = (int *)malloc(4 * n);
        for (int i = 0; i < n; i++)
        {
            _extra_values[i] = base[i];
        }
    }
    ~shared_pointers()
    {
        delete[] _extra_values;
    }
};

int main(){
    try{
        int arr[3]={100,200,300};
        shared_pointers* ptr = new shared_pointers(101,std::vector<int>{10,20},arr,3);
        std::cout<<"hello";
        delete ptr;
    }
    catch(std::exception& ex){
        std::cout<<ex.what();
    }
} */
#include<iostream>
#include<memory>


class Data{
    private:
        int* _values;
        std::size_t m_size;

    public:
        Data(int *values, std::size_t size):    m_size{size}{
            int *_values = (int*) malloc(4*size);
            for(int i=0;i<4;i++){
                _values[i]=values[i];
            }
        }
        ~Data(){
            delete[] _values;
        }

};


int main(){
    int arr[] = {1,2,3,4,5};
    try{
        std::shared_ptr<Data> sptr = std::make_shared<Data>(arr,5);
    }
    catch(std::exception& ex){
        std::cout<<ex.what();
    }
}

/*
smart pointers follow RAII and is a wrapper
acquire resource and delete on it self  
connect the resource with one object, obj goes out of scope, dest of object calls dest of other class.
*/

