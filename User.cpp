#include "User.h"

int User::getId() const {
    return id;
}

User::User(){
    id = 0;
    name = "";
}
User::User(int id, std::string username){
    this->id = id;
    this->name = username;
}

void User::setId(int id) {
    User::id = id;
}

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}
void User::addMovieToUser(Movie movie) {
    UserMovieList.add_begin(movie);
}

MovieCircularSLL User::getUserMovieList() {
    return UserMovieList;
}

MovieCircularSLL *User::getUserMovieListptr() {
    return &UserMovieList;
}

void User::setUserMovieList(const MovieCircularSLL &userMovieList) {
    UserMovieList = userMovieList;
}

int User::getMovieCount() const {
    return movieCount;
}

void User::setMovieCount(int movieCount) {
    User::movieCount = movieCount;
}

void deleteMovieFromUser(Movie movie){
    //UserMovieList.delete......
}
