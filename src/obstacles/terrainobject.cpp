#include "terrainobject.cpp"

std::ostream& operator<<(std::ostream& os, const TerrainObject& b) {
  os << b.getAsText();
  return os;
} 