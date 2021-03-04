#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <iostream>
#include "User.h"
#include "Movie.h"
#include "UserCircularDLL.h"
#include "MovieCircularSLL.h"
#include <string>

using namespace std;


class LibrarySystem {

public:
    // MovieCircularSLL obje = MovieCircularSLL();
    void addMovie(const int movieId, const std::string movieTitle, const int year);
    void deleteMovie(const int movieId);

    void addUser(const int userId, const std::string userName);
    void deleteUser(const int userId);

    void checkOutMovie(const int movieId, const int userId);
    void returnMovie(const int movieId);

    void ShowAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);
private:
    MovieCircularSLL moviesEverywhere;
    UserCircularDLL allUsers;
};


#endif // LIBRARYSYSTEM_H
