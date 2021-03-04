#include "UserCircularDLL.h"
#include <iostream>

using namespace std;

UserCircularDLL::UserCircularDLL(){
    head = nullptr;
}

void UserCircularDLL::Insert(User value) {
    node *temp;
    temp=new node;
    temp->data=value;
    temp->prev=nullptr;
    temp->next=nullptr;
    if(head==nullptr)
    {
        head=temp;
        head->next=temp;
        head->prev=temp;
    }
    else
    {
        temp->next=head;
        temp->prev=head->prev;
        head->prev->next=temp;
        head->prev=temp;
    }
}
void UserCircularDLL::Insert_Front(User value)
{
    node *temp=new node;
    temp->data=value;
    temp->prev=nullptr;
    temp->next=nullptr;
    if(head==nullptr)
    {
        Insert(value);
    }
    else
    {
        temp->prev=head->prev;
        temp->next=head;
        head->prev->next=temp;
        head->prev=temp;
        head=temp;
    }
}

int UserCircularDLL::searchUser(User value) {
    node *ptr = head;
    if (head == nullptr) {
        return -1; // userlist empty
    }
    while (true) { //ptr->next != head
        if (ptr->data.getId() == value.getId()){

            return value.getId();
        }
        if (ptr->next == head) break;
        ptr=ptr->next;
    }
    return -1; // cant find
}

User *UserCircularDLL::searchUserId(int userId) {
    node *ptr = head;
    if (head == nullptr) {
        return nullptr;
    }
    while (true) {
        if (ptr->data.getId() == userId) {
            return &(ptr->data);
        }
        if (ptr->next == head) break;
        ptr = ptr->next;
    }
    return nullptr; //cant find
}

void UserCircularDLL::deleteUser(int value) { // eksik
    node *ptr, *temp;
    ptr = head;
    // if list have only 1 element
    if (head->next == head && head->data.getId() == value) {
        temp = head;
        head = nullptr;
        free(temp);
        return;
    }
    if (ptr->data.getId() == value) { // first element deletion
        temp = ptr;
        head = head->next;
        free(temp);
        return;
    }

    while (ptr->next != head->prev) { // element deletion in between
        if (ptr->data.getId() == value) {
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            return;
        }
        ptr = ptr->next;
    }

    if (ptr->next->data.getId() == value){
        temp = ptr->next;
        ptr->next = head;
        free(temp);
        head->prev = ptr;
        return;
    }
    return;
}