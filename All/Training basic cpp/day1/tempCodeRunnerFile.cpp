class ex{
    private:
    int i;float j;

    public :
    ex(int ii=0,float jj=0.0){
        i=ii;j=jj;
    }
    void print(){
        cout<<i<<" "<<j<<"\n";
    }
};
int  main(){
    ex e1(10,20.8);
    ex e2;
    ex e3(15);
    e3=ex(19,2.9);
    ex e4=5; // {3,5.6} also works
    e1.print();
    e2.print();
    e3.print();
    e4.print();
    return 0;
}