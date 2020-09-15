#ifndef FILECONTROLLER
#define FILECONTROLLER

#include "../DTOs/ParsedObjFile.h"
#include "../Enums/ObjFileObject.h"
#include <string>

class FileController {
 public:
  ParsedObjFile ParseObjFile(std::wstring const &path);

  Enums::ObjFileObject ParseObjectName(std::wstring const &objectName);

  Entities::Vertice ParseVertice(std::vector<std::wstring> const &splittedVerticeString);

  Entities::VerticeNorm ParseVerticeNorm(
      std::vector<std::wstring> const &splittedVerticeNormString);

  Entities::VerticeTexture ParseVerticeTexture(
      std::vector<std::wstring> const &splittedVerticeTextureString);

  Entities::Polygon ParsePolygon(std::vector<std::wstring> const &splittedPolygonString);

  Entities::PolygonVertice ParsePolygonVertice(std::wstring const &polygonVerticeString);
};

#endif  // !FILECONTROLLER