#include <iostream>
#include "MovieCircularSLL.h"
#include <fstream>

using namespace std;
extern ofstream outputFile;

/*
 * Insertion of element at beginning
 */
void MovieCircularSLL::add_begin(Movie value)
{
    if (last == nullptr)
    {
        struct node *temp;
        temp = new(struct node);
        temp->info = value;
        if (last == nullptr)
        {
            last = temp;
            temp->next = last;
        }
        else
        {
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}

/*
 * Deletion of element from the list
 */
int MovieCircularSLL::delete_element(int value)
{
    if (last == nullptr) {
        return 0;
    }
    struct node *temp, *s;
    s = last->next;
    /* If List has only one element*/
    if (last->next == last && last->info.getId() == value)
    {
        temp = last;
        last = nullptr;
        free(temp);
        return 1;
    }
    if (s->info.getId() == value)  /*First Element Deletion*/
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return 1;
    }
    while (s->next != last)
    {
        /*Deletion of Element in between*/
        if (s->next->info.getId() == value)
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            return 1;
        }
        s = s->next;
    }
    /*Deletion of last element*/
    if (s->next->info.getId() == value)
    {
        temp = s->next;
        s->next = last->next;
        free(temp);
        last = s;
        return 1;
    }
    return 0;
}

/*
 * Search element in the list
 */
int MovieCircularSLL::searchMovie(Movie value)
{
    if (last == nullptr) {
        return -1;
    }
    struct node *s;
    s = last->next;
    while (s != last)
    {
        if (s->info.getId() == value.getId())
        {
            // delete s;
            return value.getId();
        }
        s = s->next;
    }
    if (s->info.getId() == value.getId())
    {
        return value.getId();
    }
    return -1;
}

Movie *MovieCircularSLL::searchMovieID(int value) {
    if (last == nullptr) {
        return nullptr; // no list
    }
    struct node *s;
    s = last->next;
    while (s != last)
    {
        if (s->info.getId() == value)
        {
            return &(s->info);
        }
        s = s->next;
    }
    if (s->info.getId() == value)
    {
        return &(s->info);
    }
    return nullptr; //no match
}

Movie MovieCircularSLL::getFirstMovie() {
    struct node *s;
    s = last->next;
    return s->info;
}

/*
 * Display Circular Link List
 */
void MovieCircularSLL::displayAllMovie()
{
    struct node *s;
    if (last == nullptr)
    {
        outputFile << "System is empty, nothing to display" << endl;
        return;
    }
    s = last->next;
    while (s != last)
    {
        outputFile << s->info.getId() << " " << s->info.getTitle() << " " << s->info.getYear();
        if (s->info.getStatus() == "not checked out") {
            outputFile << " Not checked out\n";
        } else if (s->info.getStatus() == "checked out") {
            outputFile << " Checked out by User " << s->info.getCheckedOutByUser() << endl;
        }
        s = s->next;
    }

    outputFile << s->info.getId() << " " << s->info.getTitle() << " " << s->info.getYear();
    if (s->info.getStatus() == "not checked out") {
        outputFile << " Not checked out\n";
    } else if (s->info.getStatus() == "checked out") {
        outputFile << " Checked out by User " << s->info.getCheckedOutByUser() << endl;
    }
}

void MovieCircularSLL::displayCheckedout() {
    struct node *s;
    if (last == nullptr)
    {
        return;
    }
    outputFile << "Movie id - Movie name - Year\n";
    s = last->next;
    while (s != last) {
        outputFile << s->info.getId() << " " << s->info.getTitle() << " " << s->info.getYear() << endl; //get status'u sil
        s = s->next;
    }
    outputFile << s->info.getId() << " " << s->info.getTitle() << " " << s->info.getYear() << endl;
}