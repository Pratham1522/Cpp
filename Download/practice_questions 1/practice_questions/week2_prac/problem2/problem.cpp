/* 
create vector of integers
 
#Display the result of vector filtered with the following lambdas func.


A)A predicate that identifies odd number.
B)A predivate that identifies even number divisible by 4.
c)A predicate that identifies  negative numbers in the vector

an adaptor must be created to apply filters on input data

*/

#include "Functionalities.h"
#include<functional>
#include<iostream>

int main(){
    Container data {1,2,3,4,5};
    // Adaptor(data,[](int number){return number%2==0;});
    // Adaptor(data,[](int num){return num%4==0;});
    // Adaptor(data,[](int num){if(num<0)return true; else return false;});
    FnContainer functions {PredicateToFindDivBy4,PredicateToFindNegativeNumbers, PredicateToFindOddNumbers,BindPredicateToFindNegativeNumbers};
    Adaptor(data,functions);
}

/* 
ALL TYPES OF ERRORS:
    no_declaration_matching
    redefinitions_error
    smart_pointer_construct_error
    undefined_reference
    unknown_type_error

 */

