#pragma once

#include "TerrainProxy.h"
#include "TerrainType.h"
#include <memory>
#include <vector>

class TerrainMap {
private:
    int width_;
    int height_;
    std::vector<std::vector<std::unique_ptr<Terrain>>> cells_;

public:
    TerrainMap(int width, int height);

    int getWidth() const;
    int getHeight() const;

    bool setTerrain(int x, int y, TerrainType type);
    TerrainProxy getTerrain(int x, int y) const;
    char getSymbol(int x, int y) const;
};
