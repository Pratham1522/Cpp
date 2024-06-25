#include<iostream>
#include<vector>
#include<functional>

void Adaptor(int a, std::function<bool (int)>  fn){
    if(fn(a)){
        std::cout<<"yes it is armstrong number./n";
    }
    else{
        std::cout<<"no it is not an armstrong number.\n";
    }

}

int main(){
    Adaptor(153,
    [](int a){
        int ans = a;
        int sum=0;
        while(a){
            int rem = a%10;
            sum+=rem*rem*rem;
            a=a/10;
        }
        if(sum==ans) return true;
        else return false;
    }
    );
}

// [] in lambdas is called .. used for closure.
//why lambda variables written with auto.