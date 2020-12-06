#include "ViewController.h"

void ViewController::DrawModel(HDC hdc, MainModel &model) const {
  RECT windowRect = GetWindowRectangle();

  Matrix toPerspectiveView(std::vector<std::vector<double>>{
    {1 / (aspect * tan(fov / 2)), 0, 0, 0},
    {0, 1 / tan(fov / 2), 0, 0},
    {0, 0, (farSurfaceZ + projectionSurfaceZ) / (projectionSurfaceZ - farSurfaceZ), 2 * projectionSurfaceZ * farSurfaceZ / (projectionSurfaceZ - farSurfaceZ)},
    {0, 0, -1, 0}
  });
  Matrix toViewport(std::vector<std::vector<double>>{
    {((double)windowRect.right - windowRect.left) / 2, 0, 0, ((double)windowRect.right - windowRect.left) / 2.0},
    {0, ((double)windowRect.bottom - windowRect.top) / 2.0, 0, ((double)windowRect.bottom - windowRect.top) / 2.0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  });

  std::vector<Entities::Vertice> result(model.vertices);
  /*for (auto vertice : model.vertices) {
    vertice.position.DisplayTranspose();
  }*/
  //OutputDebugString(L"\n");
  for (auto &vertice : result) {
    vertice.position = toPerspectiveView * vertice.position;
    vertice.position /= vertice.position[3][0];
    //vertice.position.DisplayTranspose();
  }
  for (auto &vertice : result) {
    vertice.position = toViewport * vertice.position;
    SetPixel(hdc, vertice.position[0][0], vertice.position[1][0], 0x00000000);
  }
  //OutputDebugString(L"\n\n");
}

RECT ViewController::GetWindowRectangle() const {
  RECT result;
  GetWindowRect(*hwnd, &result);
  return result;
}