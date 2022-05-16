#include "MessagesService.h"

#include <iostream>

void MessagesService::receive() {
    char tempMailText;
    int tempMailPriority;

    std::cout << "enter mail's text: ";
    std::cin >> tempMailText;
    std::cout << "enter mail's priority: ";
    std::cin >> tempMailPriority;

    addMailToDatabase(createMailToAdd(tempMailText,
        static_cast<Priority>(tempMailPriority)));
}

void MessagesService::receive(char mail, Priority priority) {
    if (getHowManyMails() >=getMailBoxLimit())
        removeMail(getHowManyMails()-1);

    getMails().insert(getMails().begin() + setMailIdx(priority),
                      createMailToAdd(mail, priority));
    updateMailDatabaseStatus(true, priority);
}

char MessagesService::openLastUnopenedMail() {
    if (getMails().empty())
        return '#';

    std::pair<char, std::pair<bool, Priority>> tempMail =
            getMails().front();

    showMailProperties(0);
    removeMail(0);

    return tempMail.first;
}

void MessagesService::showMailProperties(int mailIdx) {
    std::cout << "*********************";
    std::cout << "\ntext: " << getMails().at(mailIdx).first;
    std::cout << "\nindex: " << mailIdx;
    switch (getMails().at(mailIdx).second.second) {
        case DEFAULT: {
            std::cout << "\npriority: DEFAULT";
            break;
        }
        case IMPORTANT: {
            std::cout << "\npriority: IMPORTANT";
            break;
        }
        case URGENT: {
            std::cout << "\npriority: URGENT";
            break;
        }
    }
    std::cout << "\n*********************\n\n";
}

void MessagesService::removeMail(int mailIdx) {
    if (mailIdx >= getMails().size())
        return;

    updateMailDatabaseStatus(false,
                             getMails().at(mailIdx).second.second);
    getMails().erase(getMails().begin() + mailIdx);
}

int MessagesService::setMailIdx(Priority priority) {
    switch (priority) {
        case DEFAULT:
            return getHowManyImportantPriorityMails() +
                   getHowManyUrgentPriorityMails();

        case IMPORTANT:
            return getHowManyUrgentPriorityMails();

        case URGENT:
            return 0;
    }
}

std::pair<char, std::pair<bool, Priority>> MessagesService::createMailToAdd(
        char mail, Priority priority) {
    return std::make_pair(mail, std::make_pair(false, priority));
}

void MessagesService::addMailToDatabase(std::pair<char, std::pair<bool, Priority>> mail) {
    getMails().insert(getMails().begin() +
        setMailIdx(mail.second.second), mail);
    updateMailDatabaseStatus(true, mail.second.second);
}


void MessagesService::updateMailDatabaseStatus(
        bool isMailAdded, Priority priority) {

    if (isMailAdded)
        getHowManyMails()++;
    else
        getHowManyMails()--;

    switch (priority) {
        case DEFAULT: {
            if (isMailAdded)
                getHowManyDefaultPriorityMails()++;
            else
                getHowManyDefaultPriorityMails()--;
            break;
        }
        case IMPORTANT: {
            if (isMailAdded)
                getHowManyImportantPriorityMails()++;
            else
                getHowManyImportantPriorityMails()--;
            break;
        }
        case URGENT: {
            if (isMailAdded)
                getHowManyUrgentPriorityMails()++;
            else
                getHowManyUrgentPriorityMails()--;
            break;
        }
    }
}