#pragma once

#include "MailBox.h"

class MessagesService : public MailBox {
public:
    explicit MessagesService(const int mailsLimit) :
            MailBox(mailsLimit) {};

    void receive() override;
    void receive(char mail, Priority priority) override;
    char openLastUnopenedMail() override;
    void showMailProperties(int mailIdx) override;
    void removeMail(int mailIdx) override;

    int setMailIdx(Priority priority);
    std::pair<char, std::pair<bool, Priority>> createMailToAdd (
            char mail, Priority priority);
    void addMailToDatabase(std::pair<char, std::pair<bool, Priority>> mail);
    void updateMailDatabaseStatus(bool isMailAdded, Priority priority);
};
