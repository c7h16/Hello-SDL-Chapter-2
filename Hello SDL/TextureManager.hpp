
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

//load function
bool load(std::string fileName, std::string ID, SDL_Renderer *pRenderer );

//draw function
void draw(std::string ID, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE );

//drawframe function
void drawFrame( std::string ID, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE );
   


private:
    //pointers to the SDL_Texture objects using strings
    std::map<std::string, SDL_Texture*> m_textureMap;
    
protected:
    
};
#endif /* TextureManager_hpp */
