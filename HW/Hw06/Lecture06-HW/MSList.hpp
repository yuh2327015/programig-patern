    

#ifndef MSLIST_HPP
#define MSLIST_HPP

#include <vector>
#include "Star.hpp"

class MSList {
public:
    MSList();
    ~MSList();

    void addStar(Star* star);
    void renderAllStars();

private:
    std::vector<Star*> stars;
};

#endif
