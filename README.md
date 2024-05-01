# TileEditor
 A simple tilemap editor for use with future projects
 
Aims to produce custom tilemap data files that can be imported into future projects, such as
 projecting the data in a 3D space to create a tile-based 3D terrain.

Written in C++ using SDL2.

Current grid size is 32*32.

#### Tile properties
- Coordinates in the grid (x, y)
- Elevation
- Collision flag
- Type (Cosmetic; Empty / Soil / Grass / Stone / Path)

## Usage
Currently only basic inputs are handled for each tool.
- 1: Raise height 2: Lower height 3: Reset height 4: Add collision 5: Remove collision
- Q: Set to empty W: Set to soil E: Set to grass R: Set to stone T: Set to path

## Planned Features
- Visually display elevation and collision properties on each tile
- Have user-clickable GUI buttons to change tool
- Display currently used tool
- Encode grid data to an external file in useful format
- Ability to load grid data files to edit existing maps
