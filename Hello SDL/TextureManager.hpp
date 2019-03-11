
#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>


class TextureManager
{
   
public:

//static instance for creating the singleton, checks if we already have an ainstance if not creates or returns the exiting one.
static TextureManager *Instance()
    {
        if (s_pInstance == nullptr)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        
        return s_pInstance;
    }
    
//load function
bool load(std::string fileName,
          std::string ID,
          SDL_Renderer *pRenderer );

//draw function
void draw(std::string ID,
          int x, int y,
          int width, int height,
          SDL_Renderer *pRenderer,
          SDL_RendererFlip flip = SDL_FLIP_NONE );

//drawframe function - animated draws
void drawFrame( std::string ID,
               int x, int y,
               int width, int height,
               int currentRow, int currentFrame,
               SDL_Renderer *pRenderer,
               SDL_RendererFlip flip = SDL_FLIP_NONE );
   


private:
    //pointers to the SDL_Texture objects using strings it is a map with a key/value pair and named m_texturemap
    std::map<std::string, SDL_Texture*> m_textureMap;
    
    //creating a singleton of TextureManager - constructer/destructor must be private for this design pattern
    TextureManager()  {}
    ~TextureManager() {}
    
    //declare the instnace as a private
    static TextureManager* s_pInstance;
    
protected:
    
};

typedef TextureManager theTextureManager;

#endif /* TextureManager_hpp */
