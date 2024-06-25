#include "Item.h"
#include <cstring>

// class typeError:public std::exception
// {
//     char errormsg[100];

//     public:
//     typeError(){};
//     typeError(const char* msg){
//         strcpy(errormsg,msg);
//     }
//     const char* what(){
//         return errormsg;
//     }
// };
bool isValidType(int num){
    if(num==0 || num=='0'){
        return false;
    }else if(num>2 || num<1){
        return false;
    }else if(num<='a' || num >='z' || num>='A' ||num<='Z'){
        return false;
    }
    return true;
}
bool isValidOrder(int num){
    if(num==0){
        return false;
    }else if(num>100 || num<1){
        return false;
    }else if(num<='a' || num >='z' || num>='A' ||num<='Z'){
        return false;
    }
    return true;
}
Item::Item()
{ // default connstructor
    cashinhand = 100;
}

void Item::sellitem()
{
    std::cout << "****$ Welcome to McDonald Restaurant $****\n";
    while (true)
    {
        // int flag=0;
        std::cout << "\n\nPress 1 for BURGER \nPress 2 for PIZZA \n\n";
        // try{
        while(true){
            std::cout << "What would you like to have : ";
            std::cin >> Product_type;
            if(isValidType(Product_type)){
                break;
            }else{
                std::cout<<"\nPlease Enter Valid Input .\n";
            }
        }
        
        // if(Product_type !=1 && Product_type !=2){
        //     throw typeError("Wrong Input ,Order PIZZA or BURGER,try again: ");
        // }
        while(true){
            std::cout << "Enter number of items you like to have : ";
            std::cin >> Numberofitems;
            if(isValidOrder(Numberofitems)){
                break;
            }else{
                std::cout<<"\nPlease Enter Valid Input .\n";
            }
        }
        // if(Numberofitems<1 || Numberofitems>1000){
        //     throw typeError("Order Number Must be Between 1 and 1000");
        // }
        // }catch(typeError &t){
        //     std::cout<<t.what();
        //     flag=1;
        // }
        // if(flag==0){
        switch (Product_type)            // finding costperitem using producttype
        { 
        case 1:
            costperitem = 10;
            break;
        case 2:
            costperitem = 20;
        }

        int final_amount = costperitem * Numberofitems;

        if (final_amount <= cashinhand)
        { // checking balance is sufficient
            cashinhand -= final_amount;
            std::cout << "Your order is confirmed. \n";
            std::cout << "Remaining Balance :" << cashinhand;

            if (cashinhand <= 0)
            {
                std::cout << "\nBalance not sufficient. \nHave a great day \n\n ";
                break;
                std::cout << "\nWhat more would you like to have. \n";
            }
        }
        else
        {
            std::cout << "\nSorry ,Your Money is not sufficent . \nTry adding Money or try something else.\n";
        }
    }
    // }
}
