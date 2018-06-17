//
// Created by bruno on 14/06/18.
//

#ifndef BATTLECITY_GLOBAL_H
#define BATTLECITY_GLOBAL_H



#ifdef __cplusplus
extern "C" {
#endif

//DEBUGING
#ifndef NODEBUG
#define DEBUG(...) mvprintw(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

struct Position{
    double x;
    double y;
};
struct Block {
    struct Position position;
    bool unbreakable;
};
struct Tanks {
    struct Position position;
    bool ia;
};
struct Bullets {
    struct Position position;
    double dir ;
    int alive = 0;
};


#ifdef __cplusplus
}
#endif

#endif //BATTLECITY_GLOBAL_H
