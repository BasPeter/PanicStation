//
//  Controller.hpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 19/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <memory>
#include "Node.hpp"
#include "Renderer.hpp"

class Controller
{
public:
    Controller(int screen_width, int screen_height, Renderer *renderer);
    void HandleInput(bool &running, std::shared_ptr<Node> *currentNode, std::vector<std::shared_ptr<Node>> *nodes, int* money, SDL_Point goal) const;
private:
    void PlaceNewNode(bool &running, int x, int y, std::shared_ptr<Node> *currentNode, std::vector<std::shared_ptr<Node>> *nodes, int* money, SDL_Point goal) const;
    int _screen_width;
    int _screen_height;
    
    Renderer *_renderer;
};

#endif /* Controller_hpp */
