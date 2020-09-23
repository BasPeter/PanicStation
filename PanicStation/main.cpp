//
//  main.cpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 19/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//
#include <iostream>
#include "Game.hpp"
#include "Controller.hpp"
#include "Renderer.hpp"

#include "Node.hpp"

int main(int argc, const char * argv[]) {
    
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000/kFramesPerSecond};
    constexpr std::size_t kWindowWidth{600};
    constexpr std::size_t kWindowHeight{600};
    
    // Init Renderer
    Renderer renderer(kWindowWidth, kWindowHeight);
    
    //Init Controller
    Controller controller(kWindowWidth, kWindowHeight, &renderer);

    // Init and start Game
    Game game;
    game.Run(controller, renderer, kMsPerFrame);

    return 0;
}
