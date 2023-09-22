#pragma once

#include <filesystem>

#include "moveptr.h"

namespace stdfs = std::filesystem;

struct SDL_Renderer;
struct SDL_Rect;
struct SDL_FRect;

namespace sdlw {

class Window;
class Surface;
class Texture;

class Renderer {
public:
  explicit Renderer(const Window &window);

  explicit Renderer(Renderer &&) = default;

  ~Renderer();

  SDL_Renderer *get() const;

  Texture createTextureFromSurface(const Surface &surface) const;
  Texture loadImage(const stdfs::path &path) const;
  void clear() const;
  void setDrawColor(int r, int g, int b, int a = 255) const;
  void renderCopy(const Texture &texture, const SDL_Rect from,
                  const SDL_FRect &to) const;
  void renderCopy(const Texture &texture, const SDL_FRect &to) const;
  void renderCopy(const Texture &texture, const SDL_Rect from,
                  const SDL_Rect &to) const;
  void renderCopy(const Texture &texture, const SDL_Rect &to) const;
  void present() const;

private:
  MovePtr<SDL_Renderer> _renderer;
};

}
