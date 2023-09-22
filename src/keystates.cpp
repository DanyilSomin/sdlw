#include "keystates.h"

#include <SDL2/SDL.h>

#include "sdlassert.h"

namespace sdlw {

KeyStates::KeyStates() {
  _states = SDL_GetKeyboardState(&_length);
  sdlAssert(_states);
}

bool KeyStates::check(int index) const {
  if (index < 0 || index >= _length) return false;

  return _states[index];
}

}
