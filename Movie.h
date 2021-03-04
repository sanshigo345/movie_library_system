

#ifndef MOVIE_H
#define MOVIE_H

#pragma once
#include <string>

class Movie {
    int id;
    std::string title;
    int year;
    std::string status = "not checked out";
    int checkedOutByUser = 0;
public:
    Movie();

    Movie(int id, std::string title, int year);

    int getId() const;

    void setId(int id);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    int getYear() const;

    void setYear(int year);

    const std::string &getStatus() const;

    void setStatus(const std::string &status);

    int getCheckedOutByUser() const;

    void setCheckedOutByUser(int checkedOutByUser);
};


#endif //MOVIE_H
