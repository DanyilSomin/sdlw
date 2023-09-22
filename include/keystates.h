#pragma once

#include <cstdlib>

namespace sdlw {

class KeyStates {
public:
  explicit KeyStates();

  bool check(int index) const;

private:
  const uint8_t *_states = nullptr;
  int _length            = 0;
};

}
