#include "TerrainMap.h"

#include "Plains.h"
#include "Forest.h"
#include "Swamp.h"
#include "Mountains.h"
#include <stdexcept>

TerrainMap::TerrainMap(int width, int height)
    : width_(width),
      height_(height) {
    if (width_ <= 0) {
        width_ = 1;
    }
    if (height_ <= 0) {
        height_ = 1;
    }

    cells_.resize(height_);
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            cells_[y].push_back(std::make_unique<Plains>());
        }
    }
}

int TerrainMap::getWidth() const {
    return width_;
}

int TerrainMap::getHeight() const {
    return height_;
}

bool TerrainMap::setTerrain(int x, int y, TerrainType type) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        return false;
    }

    if (type == TerrainType::Plains) {
        cells_[y][x] = std::make_unique<Plains>();
    } else if (type == TerrainType::Forest) {
        cells_[y][x] = std::make_unique<Forest>();
    } else if (type == TerrainType::Swamp) {
        cells_[y][x] = std::make_unique<Swamp>();
    } else if (type == TerrainType::Mountains) {
        cells_[y][x] = std::make_unique<Mountains>();
    } else {
        return false;
    }

    return true;
}

TerrainProxy TerrainMap::getTerrain(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Terrain coordinates are out of range.");
    }

    return TerrainProxy(*cells_[y][x]);
}

char TerrainMap::getSymbol(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        return '?';
    }
    return cells_[y][x]->getSymbol();
}
