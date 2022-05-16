#pragma once

#include <deque>

enum Priority {DEFAULT, IMPORTANT, URGENT};

class MailBox {
private:
    const int maxAmountOfMail;
    int howManyMails;
    int howManyDefaultPriorityMails;
    int howManyImportantPriorityMails;
    int howManyUrgentPriorityMails;
    std::deque<std::pair<char,
        std::pair<bool, Priority>>> Mails; // mails with properties (is read and priority)

public:
    explicit MailBox(const int mailLimit) :
        maxAmountOfMail(mailLimit),
        howManyMails(0),
        howManyDefaultPriorityMails(0),
        howManyImportantPriorityMails(0),
        howManyUrgentPriorityMails(0) {};
    MailBox(const MailBox&) = delete;

    virtual void receive() = 0;
    virtual void receive(char mail, Priority priority) = 0;
    virtual char openLastUnopenedMail() = 0;
    virtual void showMailProperties(int mailIdx) = 0;
    virtual void removeMail(int mailIdx) = 0;

    int getMailBoxLimit() const {return this->maxAmountOfMail;}
    int& getHowManyMails() {return this->howManyMails;}
    int& getHowManyDefaultPriorityMails() {
        return this->howManyDefaultPriorityMails;}
    int& getHowManyImportantPriorityMails() {
        return this->howManyImportantPriorityMails;}
    int& getHowManyUrgentPriorityMails() {
        return this->howManyUrgentPriorityMails;}
    std::deque<std::pair<char, std::pair<bool, Priority>>>&
            getMails() {return this->Mails;}
    bool isMailRead (int mailIdx) const {
        return this->Mails.at(mailIdx).second.first;};
    Priority getMailPriority(int mailIdx) const {
        return this->Mails.at(mailIdx).second.second;};
};