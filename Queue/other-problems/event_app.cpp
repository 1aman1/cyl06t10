#include <iostream>

#include <queue>

struct Events_t
{
    char EventType;   /* 'S' for EventStatus */
    char StatusType;  /* Can be only one of : 'P', 'M',  'C' or 'T' */
    short RetryCount; /* E.g. 0, 1, 2, 3, etc. */

    // for temporary objects
    Events_t(){};

    // EventStatus
    Events_t(char E, char S, short R) : EventType(E),
                                        StatusType(S),
                                        RetryCount(R){};

    // EventRequest
    Events_t(char E, short R) : EventType(E),
                                RetryCount(R){};
};

class app
{
    std::queue<Events_t> myQueue;

public:
    app() {}
    void push(char, char, short);
    void push(char, short);

    Events_t pop();
    bool isEmpty();
};

bool app::isEmpty()
{
    return myQueue.empty();
}

void app::push(char EventType, char StatusType, short RetryCount)
{
    myQueue.push(Events_t(EventType, StatusType, RetryCount));
}

void app::push(char EventType, short RetryCount)
{
    myQueue.push(Events_t(EventType, RetryCount));
}

Events_t app::pop()
{
    Events_t tmp = myQueue.front();
    myQueue.pop();

    return tmp;
}

int main()
{
    app appObj;
    appObj.push('S', 'P', 0); // < EventStatus >
    appObj.push('R', 0);      // < EventRequest >
    appObj.push('S', 'M', 0); // < EventStatus >
    appObj.push('S', 'P', 0); // < EventStatus >
    appObj.push('S', 'T', 0); // < EventStatus >
    appObj.push('S', 'P', 0); // < EventStatus >
    appObj.push('S', 'C', 0); // < EventStatus >
    appObj.push('S', 'M', 0); //

    Events_t temp;
    Events_t last;

    while (!appObj.isEmpty())
    {
        temp = appObj.pop();

        if (temp.EventType == 'S') // EventStatus
        {
            std::cout << temp.EventType << ", "
                      << temp.StatusType << ", "
                      << temp.RetryCount << std::endl;

            if (temp.RetryCount < 2 && (temp.StatusType == 'C' || temp.StatusType == 'T'))
            {
                appObj.push(temp.EventType, temp.StatusType, temp.RetryCount + 1);
            }
        }

        else
        { // EventRequest
            if (last.StatusType == 'C' || last.StatusType == 'T')
            {
                std::cout << temp.EventType << ", " //   << temp.StatusType
                          << temp.RetryCount << std::endl;
            }

            else
            {
                appObj.push(temp.EventType, temp.RetryCount + 1);
            }
        }

        last = temp;
    }

    return 0;
}