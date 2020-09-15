#include "FileController.h"

#include <fstream>
#include <sstream>
#include "../Extensions/StringExtensions.h"

ParsedObjFile FileController::ParseObjFile(std::wstring const &path) {
  std::wifstream fin(path);
  std::wstring line;
  ParsedObjFile result;
  while (getline(fin, line)) {
    auto words = Split(line, ' ', false);
    std::wstring objectName = words.front();
    switch (ParseObjectName(objectName)) {
      case Enums::ObjFileObject::vertice:
        result.vertices.push_back(ParseVertice(words));
        break;
      case Enums::ObjFileObject::verticeNorm:
        result.verticeNorms.push_back(ParseVerticeNorm(words));
        break;
      case Enums::ObjFileObject::verticeTexture:
        result.verticeTextures.push_back(ParseVerticeTexture(words));
        break;
      case Enums::ObjFileObject::polygon:
        result.polygons.push_back(ParsePolygon(words));
        break;
    }
  }
  return result;
}

Enums::ObjFileObject FileController::ParseObjectName(std::wstring const &objectName) {
  if (objectName == L"v") return Enums::ObjFileObject::vertice;
  if (objectName == L"vn") return Enums::ObjFileObject::verticeNorm;
  if (objectName == L"vt") return Enums::ObjFileObject::verticeTexture;
  if (objectName == L"f") return Enums::ObjFileObject::polygon;
  if (objectName == L"#") return Enums::ObjFileObject::comment;
  return Enums::ObjFileObject::unknown;
}

Entities::Vertice FileController::ParseVertice(
    std::vector<std::wstring> const &splittedVerticeString) {
  switch (splittedVerticeString.size()) {
    case 4:
      return Entities::Vertice(StringToDouble(splittedVerticeString[1]),
                               StringToDouble(splittedVerticeString[2]),
                               StringToDouble(splittedVerticeString[3]));
    case 5:
      return Entities::Vertice(StringToDouble(splittedVerticeString[1]),
                               StringToDouble(splittedVerticeString[2]),
                               StringToDouble(splittedVerticeString[3]),
                               StringToDouble(splittedVerticeString[4]));
  }
}

Entities::VerticeNorm FileController::ParseVerticeNorm(
    std::vector<std::wstring> const &splittedVerticeNormString) {
  switch (splittedVerticeNormString.size()) {
    case 4:
      return Entities::VerticeNorm(StringToDouble(splittedVerticeNormString[1]),
                                   StringToDouble(splittedVerticeNormString[2]),
                                   StringToDouble(splittedVerticeNormString[3]));
  }
}

Entities::VerticeTexture FileController::ParseVerticeTexture(
    std::vector<std::wstring> const &splittedVerticeTextureString) {
  switch (splittedVerticeTextureString.size()) {
    case 2:
      return Entities::VerticeTexture(StringToDouble(splittedVerticeTextureString[1]));
    case 3:
      return Entities::VerticeTexture(StringToDouble(splittedVerticeTextureString[1]),
                                      StringToDouble(splittedVerticeTextureString[2]));
    case 4:
      return Entities::VerticeTexture(StringToDouble(splittedVerticeTextureString[1]),
                                      StringToDouble(splittedVerticeTextureString[2]),
                                      StringToDouble(splittedVerticeTextureString[3]));
  }
}

Entities::Polygon FileController::ParsePolygon(
    std::vector<std::wstring> const &splittedPolygonString) {
  Entities::Polygon polygon;
  for (int i = 1; i < splittedPolygonString.size(); i++) {
    polygon.vertices.push_back(ParsePolygonVertice(splittedPolygonString[i]));
  }
  return polygon;
}

Entities::PolygonVertice FileController::ParsePolygonVertice(
    std::wstring const &polygonVerticeString) {
  auto splittedPolygonVerticeString = Split(polygonVerticeString, '/');
  switch (splittedPolygonVerticeString.size()) {
    case 1:
      return Entities::PolygonVertice(StringToDouble(splittedPolygonVerticeString[0]));
    case 2:
      return Entities::PolygonVertice(StringToDouble(splittedPolygonVerticeString[0]),
                                      StringToDouble(splittedPolygonVerticeString[1]));
    case 3:
      if (splittedPolygonVerticeString[2].empty()) {
        return Entities::PolygonVertice(StringToDouble(splittedPolygonVerticeString[0]),
                                        std::nullopt,
                                        StringToDouble(splittedPolygonVerticeString[2]));
      }
      return Entities::PolygonVertice(StringToDouble(splittedPolygonVerticeString[0]),
                                      StringToDouble(splittedPolygonVerticeString[1]),
                                      StringToDouble(splittedPolygonVerticeString[2]));
  }
}
