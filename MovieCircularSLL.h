#ifndef MOVIECIRCULARSLL_H
#define MOVIECIRCULARSLL_H


#include "Movie.h"

class MovieCircularSLL {
private:
    struct node
    {
        Movie info;
        struct node *next;
    }*last;
public:
    Movie getFirstMovie();
    void add_begin(Movie value);
    int delete_element(int value);
    int searchMovie(Movie value);
    Movie *searchMovieID(int value);
    void displayAllMovie();
    void displayCheckedout();
    MovieCircularSLL() {
        last = nullptr;
    }
};

#endif //MOVIECIRCULARSLL_H
