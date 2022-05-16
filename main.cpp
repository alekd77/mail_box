#include "MessagesService.h"

int main()
{
    MessagesService gmail(3);

    gmail.receive('b', URGENT);
    gmail.receive('e', DEFAULT);
    gmail.receive('c', IMPORTANT);
    gmail.receive('a', URGENT);

    gmail.openLastUnopenedMail();
    gmail.openLastUnopenedMail();
    gmail.openLastUnopenedMail();
    gmail.openLastUnopenedMail();
    gmail.openLastUnopenedMail();

    gmail.receive();
}