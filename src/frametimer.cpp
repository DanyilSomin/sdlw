#include "frametimer.h"

#include <cmath>

#include <SDL.h>

namespace {
uint64_t framerateToPeriod(uint64_t framerate) {
  return std::round(1000.0 / framerate);
}
}

namespace sdlw {

FrameTimer::FrameTimer(uint64_t targetFramerate)
  : _timePeriod{ framerateToPeriod(targetFramerate) } {
  _lastTime = SDL_GetTicks64();
}

uint64_t FrameTimer::resetTimeBeforeNextFrame() {
  const auto result = timeBeforeNextFrame();

  reset();

  return result;
}

uint64_t FrameTimer::timeBeforeNextFrame() const {
  const auto elapsed = timeElapsed();

  if (elapsed >= _timePeriod) return 0;

  return _timePeriod - elapsed;
}

uint64_t FrameTimer::timeElapsed() const {
  return SDL_GetTicks64() - _lastTime;
}

void FrameTimer::reset() {
  _lastTime = SDL_GetTicks64();
}

}
