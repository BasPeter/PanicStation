//
//  Node.cpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 21/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "Node.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

Node::Node(int x, int y, int height): _position{x, y}, _height(height)
{
//    std::cout << "Node Contructor Called: " << this << std::endl;

}

Node::Node(Node const& node) {
//    std::cout << "Node Copy Contructor Called: " << this << std::endl;
    _position = node._position;
    _height = node._height;
    if (node._childNode != nullptr) {
    _childNode = std::make_shared<Node>(*node._childNode);
    }
}

Node& Node::operator=(const Node &source) {
//    std::cout << "Node Copy Assignment Operator Called: " << this << std::endl;
    _position = source._position;
    _height = source._height;

    return *this;
}

Node::Node(Node &&source) {
//    std::cout << "Node Move Contructor Called: " << this << std::endl;
    _position = source._position;
    _height = source._height;
    _childNode = source._childNode;

}

Node& Node::operator=(Node &&source) {
//    std::cout << "Node Move Assignment Operator Called: " << this << std::endl;
    _position = source._position;
    _height = source._height;
    _childNode = source._childNode;

    return *this;
}

Node::~Node() {
//    std::cout << "Node Destructor Called: " << this << std::endl;
}

void Node::setChildNode(std::shared_ptr<Node> node) {
    _childNode = node;
}
    
float Node::getDistanceFromNode(int x, int y) {
    return std::sqrt(std::pow(std::abs(_position.x - x), 2) + std::pow(std::abs(_position.y - y), 2));
}
