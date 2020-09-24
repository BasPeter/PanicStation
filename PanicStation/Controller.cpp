//
//  Controller.cpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 19/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "Controller.hpp"
#include <iostream>
#include "Node.hpp"
#include <cmath>

Controller::Controller(int screen_width, int screen_height, Renderer *renderer): _screen_width(screen_width), _screen_height(screen_height), _renderer(renderer){}

void Controller::PlaceNewNode(bool &running, int x, int y, std::shared_ptr<Node> *currentNode, std::vector<std::shared_ptr<Node>> *nodes, int* money, SDL_Point goal) const {
    
    bool allowed = true;
    // Get height for node from height map, any color will suffice
    int height = _renderer->getReadableRGB(x, y).r;
    int node_height = (*currentNode)->getHeight();
    int distance = (*currentNode)->getDistanceFromNode(x, y);
        
    // Calculate cost to place new node
    int heightDifference = std::abs(node_height - height);
    int cost = (height/2) + std::pow(heightDifference, 2) + distance;
        
    if ((distance < 25 || distance > 75) || height == 0) {
        allowed = false;
        std::cout << "Unable to place new node" << std::endl;
    } else if ( cost > *money ) {
        std::cout << "You do not have enough money to place this node. Cost: " << cost << ". Available money: " << *money << std::endl;
        allowed = false;
    }
        
    if (allowed) {
    // Substract money
    *money -= cost;
    std::cout << "Balance: " << *money << std::endl;
        
    // Create new Node and set new node as child node of current noder
    std::shared_ptr<Node> newNode = std::make_shared<Node>(x, y, height);
    (*currentNode)->setChildNode(newNode);
    
    // Push new node to nodes vector
    nodes->push_back(newNode);
    
    // Set the new node as the current node
    *currentNode = newNode;
        
        if ((*currentNode)->getDistanceFromNode(goal.x, goal.y) < 10) {
            std::cout << "You did it! You created the trainline for: " << 3300 - *money << std::endl;
            running = false;
        }
    
    };
    return;
}

void Controller::HandleInput(bool &running, std::shared_ptr<Node> *currentNode, std::vector<std::shared_ptr<Node>> *nodes, int* money, SDL_Point goal) const {
    SDL_Event e;
        
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
          running = false;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            PlaceNewNode(running, x, y, currentNode, nodes, money, goal);
        }
    }
}
