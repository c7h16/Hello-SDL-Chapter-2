
#include "TextureManager.hpp"

//texture loading funciton that take a file makes a suface then creates a texture then add the texture
//by its ID and pointer to the map table so it can be accessed later by the ID.

bool TextureManager::load(std::string fileName, std::string ID, SDL_Renderer *pRenderer )
{
    //create the SDL surface pointer variable
    SDL_Surface *pTempSurface = IMG_Load(fileName.c_str()); //se c_str put C++ string into proper c format
    
    //make sure it was and no longer a nullptr
    if (pTempSurface == nullptr)
    {
        return false;
    }
    
    //create the texter from the surace
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    
    //now free up the surface
    SDL_FreeSurface(pTempSurface);
    
    //put the texture into the map file
    if (pTexture != 0)
    {
        m_textureMap[ID] = pTexture;
        return true;
    }
    
    return false;
}

//this is funciton to draw a single item not an animation.

void TextureManager::draw(std::string ID, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip )
{
    //create the rectangle for the source and destinations
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    
    //single image source starts at 0 on both axes
    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    
    //width of both source and destination is equal and set by the funciton call
    sourceRectangle.w = destinationRectangle.w = width;
    sourceRectangle.h = destinationRectangle.h = height;
    
    //destination location is set when the function is called
    destinationRectangle.x = x;
    destinationRectangle.y = y;
    
    //render images to screen
    SDL_RenderCopyEx(pRenderer,
                     m_textureMap[ID],
                     &sourceRectangle,
                     &destinationRectangle,
                     0,
                     0,
                     flip);
}

//drawframe function
void TextureManager::drawFrame( std::string ID, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip )
{
    
}
