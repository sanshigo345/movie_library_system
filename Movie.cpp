//
// Created by Bugra on 28/11/2020.
//

#include "Movie.h"


Movie::Movie(){
    id = 0;
    title = "";
    year = 0;
}

Movie::Movie(int id, std::string title, int year){
    this->id = id;
    this->title = title;
    this->year = year;
}

int Movie::getId() const {
    return id;
}

void Movie::setId(int id) {
    Movie::id = id;
}

const std::string &Movie::getTitle() const {
    return title;
}

void Movie::setTitle(const std::string &title) {
    Movie::title = title;
}

int Movie::getYear() const {
    return year;
}

void Movie::setYear(int year) {
    Movie::year = year;
}

const std::string &Movie::getStatus() const {
    return status;
}

void Movie::setStatus(const std::string &status) {
    Movie::status = status;
}

int Movie::getCheckedOutByUser() const {
    return checkedOutByUser;
}

void Movie::setCheckedOutByUser(int checkedOutByUser) {
    Movie::checkedOutByUser = checkedOutByUser;
}
