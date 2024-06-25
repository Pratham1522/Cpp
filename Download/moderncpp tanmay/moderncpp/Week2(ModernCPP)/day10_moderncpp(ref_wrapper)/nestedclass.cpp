// #include<iostream>

// class Parent{
//     public:
//         class Child{
//             private:
//                 int childnumber{0};
//                 std::string childname{"child"};
//             public:
//                 Child(int x,std::string n): childnumber(x),childname(n){}
//                 void Print(){
//                     std::cout<<childname<<" "<<childnumber<<"\n";
//                 }
//         };
//     private:
//     int number{0};
//     std::string parentname{""};
//     Child ch{};
//     public:
//     Parent(int n,std::string name): number(n), parentname(name){}
//         void print(){
//             std::cout<<number<<" "<<parentname<<"\n";
//         }
//         void solve(){
//             ch.Print();
//         }
// };

// int main(){
//     Parent p(10,"tanmay");
//     p.print();
//     p.solve();
// }