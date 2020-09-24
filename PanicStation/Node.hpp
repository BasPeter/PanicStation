//
//  Node.hpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 21/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <vector>
#include <memory>
#include <SDL2/SDL.h>

class Node
{
public:
    Node(int x, int y, int height);
    Node(Node const& node);
    Node &operator=(const Node &source);
    Node(Node &&source);
    Node &operator=(Node &&source);
    ~Node();
    
    
    SDL_Point getPosition() { return _position; };
    
    std::shared_ptr<Node> const getChildNode() { return _childNode; };
    bool hasChildNode() { return _childNode != nullptr; };
    void setChildNode(std::shared_ptr<Node> node);
    float getDistanceFromNode(int x, int y);
    int getHeight() { return _height; }
    
protected:
    SDL_Point _position;
    
private:
    std::shared_ptr<Node> _childNode;
    int _height;
    
};

#endif /* Node_hpp */
