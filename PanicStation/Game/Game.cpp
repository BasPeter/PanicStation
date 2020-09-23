//
//  Game.cpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 19/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "Game.hpp"
#include "Controller.hpp"
#include "Node.hpp"

Game::Game()
{
    // Init new empty _nodes vector;
    _nodes = std::vector<std::shared_ptr<Node>>();
    
    // Place starting node into vector
    // Init with known height
    _currentNode = std::make_shared<Node>(Node(200, 522, 111));
    _nodes.push_back(_currentNode);
    
    _goal = {151, 55};
    
    std::cout << "Hey, welcome to Panic Station, a small little concept for a game." << std::endl;
    std::cout << "Your task is to build a trainline from the bottom of the island to the top." << std::endl;
    std::cout << "But unfortunaly you have a limited amount of money. 3300 to be exact." << std::endl;
    std::cout << "The cost of a piece of trainine depends on the height difference and the length of the piece" << std::endl;
    std::cout << "Good luck." << std::endl;
    
}

void Game::Update() {
}

void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration)
{
    
    Uint32 titleTimestamp = SDL_GetTicks();
    
    Uint32 frameStart;
    Uint32 frameEnd;
    Uint32 frameDuration;
    
    int frameCount{0};
    
    bool running = true;
        
    while (running) {
        
        // Start of game loop
        frameStart = SDL_GetTicks();
        
        // Handle Input
        controller.HandleInput(running, &_currentNode, &_nodes, &_money, _goal);
        
        // Update game state
        Update();
        
        // Render
        renderer.Render(_currentNode, _nodes, _goal);
        
        
        // End of game loop
        frameEnd = SDL_GetTicks();
        frameDuration = frameEnd - frameStart;
        
        // Time Control
        if (frameDuration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frameDuration);
        }
        
        frameCount++;
        if (frameStart - titleTimestamp >= 1000) {
            renderer.UpdateWindowTitle(frameCount);
            frameCount = 0;
            titleTimestamp = frameEnd;
        }
        
        
        
        
    }
}
