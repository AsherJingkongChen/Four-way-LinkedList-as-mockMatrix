#ifndef COMMUNITY_H
#define COMMUNITY_H

size_t at(size_t width, size_t _row, size_t _col); //return mock at number of a mock 2-D array
typedef struct Community Community; //node
struct Community {
    int number;
    Community* up;
    Community* down;
    Community* left;
    Community* right;
};
Community* community(size_t row, size_t col); //constructor which returns a pointer to the array
void del_community(Community* location);
void see_community(Community* location, size_t row, size_t col);

#endif