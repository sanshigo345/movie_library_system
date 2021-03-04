#ifndef USER_H
#define USER_H
#pragma once
#include <string>
#include "MovieCircularSLL.h"

class User {
    int id;
    std::string name;
    // Circular singly linkedlist listofmovies checkedout by user
    MovieCircularSLL UserMovieList;
    int movieCount = 0;
public:
    User();

    User(int id, std::string username);

    MovieCircularSLL *getUserMovieListptr();

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    void addMovieToUser(Movie);

    void deleteMovieFromUser(Movie);

    MovieCircularSLL getUserMovieList();

    void setUserMovieList(const MovieCircularSLL &userMovieList);

    int getMovieCount() const;

    void setMovieCount(int movieCount);

};

#endif //USER_H
