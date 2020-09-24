//
//  Game.hpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 19/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <stdio.h>
#include <memory>
#include "Renderer.hpp"
#include "Controller.hpp"
#include "Node.hpp"

class Game
{
public:
    
    Game();
    void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration);
    
    int getMoney() const { return _money; };
    
private:
    void Update();
    
    std::shared_ptr<Node> _currentNode;
    std::vector<std::shared_ptr<Node>> _nodes;
    
    SDL_Point _goal;
    
    int _money{3300};
    
};

#endif /* Game_hpp */
