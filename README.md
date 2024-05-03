# TileEditor
A simple tilemap editor program. It is intended to be used as a tool for developing game levels. It aims
 to export tilemap data files which can be read by other programs to project their data into a game world. For
 example, to create terrain by projecting each tile as a quad in 3D space, at their given elevation.

Currently only 32*32 tilemap grids are supported.

Written in C++ using SDL2.

## Usage
#### Controls
Currently only basic inputs are handled for each tool.
- 1: Raise height 2: Lower height 3: Reset height 4: Add collision 5: Remove collision
- Q: Set to empty W: Set to soil E: Set to grass R: Set to stone T: Set to path
- A: Set warping to true S: Set warping to false

#### Tile properties
Each tile has a series of properties. These can be expanded in Tile.h
- Coordinates in the grid (x, y)
- Elevation
- Collision flag
- Type (Cosmetic; Empty / Soil / Grass / Stone / Path)
- Warping flag (Allow tile to have corner vertices moved to stitch terrain)
- Coordinate X Y Z arrays for each of the four corners

## Planned Features
- Visually display elevation and collision properties on each tile
- Have user-clickable GUI buttons to change tool
- Display currently used tool
- Encode grid data to an external file in useful format
- Ability to load grid data files to edit existing maps
