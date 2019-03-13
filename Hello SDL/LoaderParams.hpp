
#ifndef LoadParams_hpp
#define LoadParams_hpp

#include <string>

class LoaderParams
{
public:
    
    LoaderParams(int x, int y, int width, int height, std::string textureID) :
    m_xCoord(x), m_yCoord(y), m_width(width), m_height(height), m_textureID(textureID)
    
    {
        
    }
    
    //getters for the member variables 
    int getX() const { return m_xCoord; }
    int getY() const { return m_yCoord; }
    
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    
    std::string getTextureID() const { return m_textureID; }
    
private:
    
    int m_xCoord;
    int m_yCoord;
    
    int m_width;
    int m_height;
    
    std::string m_textureID;
    
};


#endif /* LoadParams_hpp */
