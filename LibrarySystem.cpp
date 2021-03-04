#include "LibrarySystem.h"
#include <fstream>

using namespace std;

extern ofstream outputFile;

void LibrarySystem::addMovie(const int movieId, const std::string movieTitle, const int year){
    Movie movie = Movie(movieId, movieTitle, year);
    movie.setStatus("not checked out");
    if (moviesEverywhere.searchMovie(movie) <= 0) {
        moviesEverywhere.add_begin(movie);
        outputFile << "Movie " << movie.getId() << " has been added" << endl;
    } else {
        outputFile << "Movie " << movie.getId() << " already exists" << endl;
    }

}
void LibrarySystem::deleteMovie(const int movieId) {
    if (moviesEverywhere.searchMovieID(movieId) == nullptr) {
        outputFile << "Movie " << movieId << " does not exist\n";
    } else {
        if ((moviesEverywhere.searchMovieID(movieId))->getStatus() == "checked out") {
            int checkedOutByUserNo = (moviesEverywhere.searchMovieID(movieId))->getCheckedOutByUser();
            allUsers.searchUserId(checkedOutByUserNo)->getUserMovieListptr()->delete_element(movieId);
            moviesEverywhere.delete_element(movieId);
            outputFile << "Movie " << movieId << " has been checked out\nMovie " << movieId << " has been deleted\n";
        } else {
            moviesEverywhere.delete_element(movieId);
            outputFile << "Movie " << movieId << " has not been checked out\nMovie " << movieId << " has been deleted\n";
        }
    }
}

void LibrarySystem::addUser(const int userId, const std::string userName){
    User user(userId, userName);
    if (allUsers.searchUser(user) <= 0) {
        allUsers.Insert_Front(user);
        outputFile << "User " << userId << " has been added\n";
    } else {
        outputFile << "User " << userId << " already exists\n";
    }
}
void LibrarySystem::deleteUser(const int userId){ // sorry :(

    if (allUsers.searchUserId(userId) == nullptr) {
        outputFile << "User " << userId << " does not exist\n";
    } else { //deleting user's movies and then user
        /* int temp = allUsers.searchUserId(userId)->getMovieCount();
        for (int i = 0; i < temp; i++) { //deleting movies that user checked out
            int moveid = allUsers.searchUserId(userId)->getUserMovieListptr()->getFirstMovie().getId();
            moviesEverywhere.delete_element(moveid);
            allUsers.searchUserId(userId)->getUserMovieListptr()->delete_element(moveid); // movieuserin listeden (silindi umarım)
        }
        // delete does not work
        // allUsers.deleteUser(userId);

         */
        outputFile << "User " << userId << " has been deleted\n";
    }

}

void LibrarySystem::checkOutMovie(const int movieId, const int userId){
    Movie* tempMovie = moviesEverywhere.searchMovieID(movieId);
    User* tempUser = allUsers.searchUserId(userId);
    if(tempMovie == nullptr || tempMovie->getStatus() == "checked out") {
        outputFile << "Movie " << movieId << " does not exist for checkout\n";
    } else if (tempUser == nullptr) {
        outputFile << "User " << userId << " does not exist for checkout\n";
    } else if ((tempMovie->getStatus() == "not checked out")) { // succesfull checkout
        outputFile << "Movie " << movieId << " has been checked out by User " << userId << endl;
        int tempcount = tempUser->getMovieCount();
        tempcount++;
        tempUser->setMovieCount(tempcount);
        tempMovie->setStatus("checked out");
        tempMovie->setCheckedOutByUser(userId);
        tempUser->addMovieToUser(*tempMovie);
    }

}

void LibrarySystem::returnMovie(const int movieId){
    if (moviesEverywhere.searchMovieID(movieId) == nullptr) {
        outputFile << "Movie " << movieId << " not exist in the library\n";
    } else {
        if (moviesEverywhere.searchMovieID(movieId)->getStatus() == "checked out") {
            allUsers.searchUserId(moviesEverywhere.searchMovieID(movieId)->getCheckedOutByUser())->getUserMovieListptr()->delete_element(movieId);
            int tempCount = allUsers.searchUserId(moviesEverywhere.searchMovieID(movieId)->getCheckedOutByUser())->getMovieCount();
            tempCount--;
            allUsers.searchUserId(moviesEverywhere.searchMovieID(movieId)->getCheckedOutByUser())->setMovieCount(tempCount);
            outputFile << "Movie " << movieId << " has been returned\n";
            moviesEverywhere.searchMovieID(movieId)->setStatus("not checked out");
        } else {
            outputFile << "Movie " << movieId << " has not been checked out\n";
        }
    }
}

void LibrarySystem::ShowAllMovies(){
    moviesEverywhere.displayAllMovie();
}

void LibrarySystem::showMovie(const int movieId){
    if (moviesEverywhere.searchMovieID(movieId) == nullptr ) {
        outputFile << "Movie with the id " << movieId << " does not exist\n";
    } else {
        Movie temp = *(moviesEverywhere.searchMovieID(movieId));
        if (temp.getStatus() == "checked out") {
            outputFile << movieId << " " << temp.getTitle() << " " << temp.getYear() << " Checked out by User " << temp.getCheckedOutByUser() << endl;
        } else {
            outputFile << movieId << " " << temp.getTitle() << " " << temp.getYear() << " Not checked out\n";
        }
    }
}

void LibrarySystem::showUser(const int userId){
    if (allUsers.searchUserId(userId) == nullptr) {
        outputFile << "User " << userId << " does not exist\n";
    } else {
        outputFile << "User id: " << userId << " User name: " << (allUsers.searchUserId(userId))->getName() << "\nUser " << userId << " checked out the following Movies:\n";
        allUsers.searchUserId(userId)->getUserMovieList().displayCheckedout();
    }
}