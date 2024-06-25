#include<iostream>

class array{
    private:
        int* data;
    public:
        array(){
            std::cout<<"constructor"<<std::endl;
            data = new int[10];
            for(int i=0;i<10;i++){
                data[i] = i;
            }
        }
        array(array &rhs){
            std::cout<<"copy constructor"<<std::endl;
            data = new int[10];
            for(int i=0;i<10;i++){
                data[i] = rhs.data[i];
            }
        }
        void print(){
            for(int i=0;i<10;i++){
                std::cout<<i<<std::endl;
            }
        }
        ~array(){
            std::cout<<"destructor"<<std::endl;
            delete[] data;
        }
};

int main(){
    array ar;
    ar.print();
    array ar2 = ar;
    ar2.print();
}