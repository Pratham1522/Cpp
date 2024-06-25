#include <iostream>
#include <thread>
#include <mutex>

class DataOperation
{
private:
    std::mutex mt;
    int _amount{1000};

public:
    DataOperation() = default;
    DataOperation(const DataOperation &) = delete;
    DataOperation &operator=(const DataOperation &) = delete;
    DataOperation(DataOperation &&) = default;
    DataOperation &operator=(DataOperation &&) = delete;
    ~DataOperation() = default;
    DataOperation(int amount) : _amount{amount} {}

    int amount() const { return _amount; }
    void setAmount(int amount) { _amount = amount; }

    void Withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
            std::lock_guard<std::mutex> lk(mt);
            _amount -= 10;
        }
    }

    void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
            std::lock_guard<std::mutex> lk(mt);
            _amount += 10;
        }
    }
};

int main(){
    DataOperation d1;
    std::thread t1(&DataOperation::Withdraw,std::ref(d1));
    std::thread t2(&DataOperation::Deposit,&d1);
    if(t1.joinable()){t1.join();}
    if(t2.joinable()){t2.join();}
    std::cout<<d1.amount()<<"\n";
}
