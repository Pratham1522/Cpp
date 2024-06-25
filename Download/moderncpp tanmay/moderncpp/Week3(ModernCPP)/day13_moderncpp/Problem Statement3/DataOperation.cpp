#include "DataOperation.h"

DataOperation *DataOperation::_only_object{nullptr};

DataOperation *DataOperation::GetInstance(int val)
{
    if (_only_object)
    {
        // already created since it is not null
        return _only_object;
    }
    else
    {
        _only_object = new DataOperation(val);
        return _only_object;
    }
}

void DataOperation::Producer_Input()
{
    std::cin >> m_value;
    // trigger a signal after cin is done, to indicate that consumer.
    // can proceed with square calculation.
    m_flag = true;
    m_cv.notify_one();
}

void DataOperation::Consumer_Operation()
{
    int *m_result_value = (int *)malloc(4);
    //////////////////////////
    std::unique_lock<std::mutex> ul(m_mt);

    m_cv.wait(ul, [&]()
              { return m_flag; });

    *m_result_value = m_value * m_value;
    std::cout << " Square Calculation is complete " << *m_result_value << std::endl;
}