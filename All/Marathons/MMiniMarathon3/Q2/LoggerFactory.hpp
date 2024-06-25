#include "Console.hpp"
#include "Service.hpp"
#include "File.hpp"

#define line() cout<<"---------------------------- \n";

class LoggerFactory
{
    public:
    static ILogger* CreateLoggers()
    {
        return new Console(new Service(new File(new NullLogger())));
    }
};
void Start(ILogger *logger)
{
    line();
    logger->log("Product Added");
    line();
}
