#include "renderer.h"

#include "sdlassert.h"
#include "surface.h"
#include "texture.h"
#include "window.h"

#include <SDL2/SDL.h>
#include <SDL_image.h>

namespace sdlw {

Renderer::Renderer(const Window &window)
  : _renderer{ SDL_CreateRenderer(window.get(), -1,
                                  SDL_RENDERER_ACCELERATED) } {
  sdlw::sdlAssert(_renderer.get());
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(_renderer.get());
}

SDL_Renderer *Renderer::get() const {
  return _renderer.get();
}

Texture Renderer::createTextureFromSurface(const Surface &surface) const {
  return Texture{ SDL_CreateTextureFromSurface(
    const_cast<SDL_Renderer *>(get()), surface.get()) };
}

Texture Renderer::loadImage(const stdfs::path &path) const {
  return Texture{ IMG_LoadTexture(get(), path.c_str()) };
}

void Renderer::clear() const {
  sdlAssert(SDL_RenderClear(get()));
}

void Renderer::setDrawColor(int r, int g, int b, int a /*= 255*/) const {
  sdlAssert(SDL_SetRenderDrawColor(get(), r, g, b, a));
}

void Renderer::renderCopy(const Texture &texture, const SDL_Rect from,
                          const SDL_FRect &to) const {
  sdlAssert(SDL_RenderCopyF(get(), texture.get(), &from, &to));
}

void Renderer::renderCopy(const Texture &texture, const SDL_FRect &to) const {
  sdlAssert(SDL_RenderCopyF(get(), texture.get(), nullptr, &to));
}

void Renderer::renderCopy(const Texture &texture, const SDL_Rect from,
                          const SDL_Rect &to) const {
  sdlAssert(SDL_RenderCopy(get(), texture.get(), &from, &to));
}

void Renderer::renderCopy(const Texture &texture, const SDL_Rect &to) const {
  sdlAssert(SDL_RenderCopy(get(), texture.get(), nullptr, &to));
}

void Renderer::present() const {
  SDL_RenderPresent(get());
}

}
