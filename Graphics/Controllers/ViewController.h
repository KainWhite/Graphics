#ifndef VIEWCONTROLLER
#define VIEWCONTROLLER

#include "../Models/MainModel.h"

class ViewController {
 public:
  double const projectionSurfaceZ = -0.5;
  double const farSurfaceZ = -1000;
  double const aspect = 16.0 / 9;
  double const fov = 45 * 3.1415 / 180;
  HWND *hwnd;

  ViewController(HWND *hwnd) : hwnd(hwnd) {}

  void DrawModel(HDC hdc, MainModel &model) const;
  RECT GetWindowRectangle() const;
};

#endif // VIEWCONTROLLER