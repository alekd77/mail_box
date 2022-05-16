cmake_minimum_required(VERSION 3.19)
project(mail_box)

set(CMAKE_CXX_STANDARD 14)

add_executable(mail_box main.cpp MailBox.h MessagesService.cpp MessagesService.h)