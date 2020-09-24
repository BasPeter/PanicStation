//
//  Renderer.hpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 19/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Node.hpp"

class Renderer
{
public:
    Renderer(std::size_t screen_width, std::size_t screen_height);
    ~Renderer();
    
    void Render(std::shared_ptr<Node> currentNode, std::vector<std::shared_ptr<Node>> nodes, SDL_Point goal);
    void UpdateWindowTitle(int fps);
    SDL_Color getReadableRGB(int x, int y);
private:
    
    SDL_Window *_sdl_window;
    SDL_Renderer *_sdl_renderer;
    SDL_Texture * _background_texture = NULL;
    SDL_Surface * _heightmap_surface = NULL;
    
    const std::size_t _screen_width;
    const std::size_t _screen_height;
    
    SDL_Texture* LoadTexture(std::string path);
    
    Uint32 getPixel(int x, int y);
    void RenderPointer(int x, int y, std::shared_ptr<Node> node);
};

#endif /* Renderer_hpp */
