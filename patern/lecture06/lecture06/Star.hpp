// Star.hpp

#ifndef STAR_HPP
#define STAR_HPP

class Star {
public:
    Star(); 
    ~Star(); 

    void setPosition(float x, float y); 
    void setColor(float r, float g, float b); 
    void render(); 

private:
    float m_X, m_Y; 
    float m_R, m_G, m_B; 
};

#endif 
