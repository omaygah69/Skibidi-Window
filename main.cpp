#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <iostream>

const int ScreenHeight = 500;
const int ScreenWidth = 900;
SDL_Window* GraphicsApplicationWindow = nullptr;
SDL_GLContext OpenGLContext = nullptr;
bool Quit = false; //true for quit

// Needs Glad Library to work
// void getOpenGLInfo(){
//   std::cout << "Vendor: " << glGetString(GL_VENDOR) << "\n";
//   std::cout << "Version: " << glGetString(GL_VERSION) << "\n";
// }

void Initialize(){
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "Could Not Initialize SDL Video Subsystem \n";
    exit(1);
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  GraphicsApplicationWindow = SDL_CreateWindow(
                                               "Skibidi Osaker", 0, 0, ScreenWidth, ScreenHeight, SDL_WINDOW_OPENGL);

  if(GraphicsApplicationWindow == nullptr){
    std::cout << "Could Not Create SDL Window\n";
    exit(1);
  }

  OpenGLContext = SDL_GL_CreateContext(GraphicsApplicationWindow);
  if(OpenGLContext == nullptr){
    std::cout << "Could not Create OpenGL Context.\n";
    exit(1);
    
  }
}

void Input() {
  SDL_Event event;
  while(SDL_PollEvent(&event) != 0) {
    if (event.type == SDL_QUIT) {
      std::cout << "Adios!\n";
      Quit = true;
    }

  }
}
void PreDraw() {}
void Draw(){}

void MainLoop(){
  while (!Quit){
    Input();
    PreDraw();
    Draw();
    SDL_GL_SwapWindow(GraphicsApplicationWindow); //Update The Window
  }
}

void CleanUp() {
  SDL_DestroyWindow(GraphicsApplicationWindow);
  SDL_Quit();
}

int main(){
  Initialize();
  MainLoop();
  CleanUp();
  return 0;
}
