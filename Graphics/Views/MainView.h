#ifndef MAINVIEW
#define MAINVIEW

#include <vector>
#include "../Entities/Vertice.h"

class MainView {
 public:
  void DrawVertices(std::vector<Entities::Vertice> const &vertices);
};

#endif  // !MAINVIEW
