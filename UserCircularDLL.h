//
// Created by Bugra on 29/11/2020.
//

#ifndef USERCIRCULARDLL_H
#define USERCIRCULARDLL_H


#include "User.h"

class UserCircularDLL {
    struct node {
        User data;
        node *next;
        node *prev;
    }*head;
    int count = 0;
public:
    UserCircularDLL();
    void deleteUser(int value);
    void Insert(User);
    void Insert_Front(User);
    void display();
    int searchUser(User value);
    User *searchUserId(int userId);
};


#endif //USERCIRCULARDLL_H
