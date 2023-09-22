#pragma once

#include <cstdint>

namespace sdlw {

class FrameTimer {
public:
  explicit FrameTimer(uint64_t targetFramerate);

  uint64_t resetTimeBeforeNextFrame();
  uint64_t timeBeforeNextFrame() const;

  uint64_t timeElapsed() const;

  void reset();

private:
  uint64_t _lastTime;

  const uint64_t _timePeriod;
};

}
