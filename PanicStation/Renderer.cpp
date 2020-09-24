//
//  Renderer.cpp
//  PanicStation
//
//  Created by Bas Peter Dijkema on 19/09/2020.
//  Copyright © 2020 Bas Peter Dijkema. All rights reserved.
//

#include "Renderer.hpp"

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height): _screen_width(screen_width), _screen_height(screen_height)
{
    //Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize.." << std::endl;
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }
    
    //Create window
    _sdl_window = SDL_CreateWindow("Panic Station", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screen_width, _screen_height, SDL_WINDOW_SHOWN);
    
    if (nullptr == _sdl_window) {
        std::cout << "Window could not be created.." << std::endl;
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }
    
    // Setup SDL_Image
    int imgFlags = IMG_INIT_JPG;
    if ( !(IMG_Init(imgFlags) & imgFlags ) ) {
        std::cout << "SDL_IMG could not be initialized.." << std::endl;
        std::cout << IMG_GetError() << std::endl;
    }
    
    // Create Renderer
    _sdl_renderer = SDL_CreateRenderer(_sdl_window, -1, SDL_RENDERER_ACCELERATED);
      
      if (nullptr == _sdl_renderer) {
          std::cout << "Renderer could not be created.." << std::endl;
          std::cout << "SDL Error: " << SDL_GetError() << std::endl;
      }
    
    // Load Background image
    _background_texture = LoadTexture("Assets/BG_Color.jpg");
    
    _heightmap_surface = IMG_Load("Assets/BG_Height_Map.jpg");
    if (_background_texture == NULL || _heightmap_surface == NULL) {
        std::cout << "Could not load map" << std::endl;
        std::cout << IMG_GetError() << std::endl;
    }
    
}

Renderer::~Renderer() {
    
    SDL_DestroyTexture(_background_texture);

    SDL_FreeSurface(_heightmap_surface);
    
    SDL_DestroyWindow(_sdl_window);
    SDL_Quit();
}

void Renderer::Render(std::shared_ptr<Node> currentNode, std::vector<std::shared_ptr<Node>> nodes, SDL_Point goal) {
    SDL_SetRenderDrawColor(_sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(_sdl_renderer);
            
    SDL_RenderCopy(_sdl_renderer, _background_texture, NULL, NULL);

    // render Nodes
    SDL_SetRenderDrawColor(_sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    
    int node_center_x;
    int node_center_y;
    int node_pos_x;
    int node_pos_y;
        
    for (int n = 0; n < nodes.size(); n++) {
        
        node_pos_x = nodes[n]->getPosition().x;
        node_pos_y = nodes[n]->getPosition().y;

        for (int t = 0; t < 360; t+=10)
        {
            node_center_x = node_pos_x + 3 * cos(t);
            node_center_y = node_pos_y + 3 * sin(t);
            SDL_RenderDrawPoint(_sdl_renderer, node_center_x, node_center_y);
        }
    }

    // render lines
    SDL_SetRenderDrawColor(_sdl_renderer, 0x1E, 0xFF, 0xCC, 0xFF);
    
    int x_1;
    int y_1;
    int x_2;
    int y_2;

    for (int n = 0; n < nodes.size(); n++) {

        if (nodes[n]->getChildNode() != nullptr) {
            
            x_1 = nodes[n]->getPosition().x;
            y_1 = nodes[n]->getPosition().y;
            x_2 = nodes[n]->getChildNode()->getPosition().x;
            y_2 = nodes[n]->getChildNode()->getPosition().y;

            SDL_RenderDrawLine(_sdl_renderer, x_1, y_1, x_2, y_2);
        }
    }
    
    SDL_SetRenderDrawColor(_sdl_renderer, 0xCC, 0xFF, 0xFF, 0xFF);
    
    int goal_center_x;
    int goal_center_y;
        
    for (int n = 0; n < nodes.size(); n++) {

        for (int t = 0; t < 360; t+=10)
        {
            node_center_x = goal.x + 6 * cos(t);
            node_center_y = goal.y + 6 * sin(t);
            SDL_RenderDrawPoint(_sdl_renderer, node_center_x, node_center_y);
        }
    }
    
    int x, y;
    SDL_GetMouseState(&x, &y);
    RenderPointer(x, y, currentNode);
    
    // Update Screen
    SDL_RenderPresent(_sdl_renderer);
}

void Renderer::RenderPointer(int x, int y, std::shared_ptr<Node> node) {
    int distance = node->getDistanceFromNode(x, y);
    // auto [node_x, node_y] = node->getPosition();
    int node_x = node->getPosition().x;
    int node_y = node->getPosition().y;
    if ((distance < 25 || distance > 75) || getReadableRGB(x, y).r == 0) {
        SDL_SetRenderDrawColor(_sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    } else {
        SDL_SetRenderDrawColor(_sdl_renderer, 0x00, 0xFF, 0x00, 0xFF);
    }
    SDL_RenderDrawLine(_sdl_renderer, x, y, node_x, node_y);
}

void Renderer::UpdateWindowTitle(int fps) {
    std::string title {"Panic Station, FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(_sdl_window, title.c_str());
}

SDL_Texture* Renderer::LoadTexture(std::string path) {
    SDL_Texture* loadedTexture = NULL;
    
    SDL_Surface* loadedSurface = IMG_Load(path.c_str() );
    if (loadedSurface == NULL) {
        std::cout << "Unable to load image.." << std::endl;
        std::cout << IMG_GetError() << std::endl;
    } else {
        loadedTexture = SDL_CreateTextureFromSurface(_sdl_renderer, loadedSurface);
    }
    
    return loadedTexture;
}

Uint32 Renderer::getPixel(int x, int y) {
    int bpp = _heightmap_surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)_heightmap_surface->pixels + y * _heightmap_surface->pitch + x * bpp;
    switch (bpp)
    {
        case 1:
            return *p;
            break;

        case 2:
            return *(Uint16 *)p;
            break;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;
                break;

            case 4:
                return *(Uint32 *)p;
                break;

            default:
                return 0;       /* shouldn't happen, but avoids warnings */
          }
    }

SDL_Color Renderer::getReadableRGB(int x, int y) {
    SDL_Color rgb = SDL_Color();
    SDL_GetRGB(getPixel(x, y), _heightmap_surface->format, &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}
