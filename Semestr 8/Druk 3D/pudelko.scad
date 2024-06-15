// Run with default values: $ openscad pudelko.scad
// Run with configured params: $ openscad PARAMS pudelko.scad
// Params:
// -D size_x=VAL - horizontal size in mm (default: 120, min: 10, max: 250)
// -D size_y=VAL - vertical size in mm (default: 180, min: 10, max: 250)
// -D wall_thickness=VAL - walls thickness in mm (default: 2, min: 1, max: 5)
// -D border_wall_height=VAL height of bordering walls in mm (default: 40, min: 5, max: 100)
// -D divider_wall_height=VAL height of divider walls in mm (default: 35, min: border_wall_height, max: 100)
// -D compartments_vertical=VAL number of vertical dividers (default: 3, min: 0, max: (size_x / compartments_vertical) > wall_thickness + 2)
// -D compartments_horizontal=VAL number of horizontal dividers (default: 3, min: 0, max: (size_y / compartments_horizontal) > wall_thickness + 2)
// -D lid_fitment=VAL tolerance for the lid fitment in mm, default is tight fit (default: 0.1, min: 0.1, max 0.2)
// -D lid_sides=VAL length of lid sides in mm (default: 6, min: 2, max: 10)

module base(sizeX, sizeY, wallThickness) {
    cube([sizeX, sizeY, wallThickness]);
}

module borderWalls(sizeX, sizeY, wallHeight, wallThickness) {
    // Vertical
    cube([sizeX, wallThickness, wallHeight]);
    translate([0, sizeY - wallThickness, 0]) cube([sizeX, wallThickness, wallHeight]);
    
    // Horizontal
    cube([wallThickness, sizeY, wallHeight]);
    translate([sizeX - wallThickness, 0, 0]) cube([wallThickness, sizeY, wallHeight]);
}

module dividerWalls(sizeX, sizeY, wallThickness, dividerWallHeight, compsHor, compsVer) {
    // Vertical
    if (compsVer > 1) {
        spacingVer = sizeX / compsVer;
        for(i = [1 : compsVer - 1]) {
            translate([spacingVer * i, 0, 0]) cube([wallThickness, sizeY, dividerWallHeight]);
        }
    }
    
    // Horizontal
    if (compsHor > 1) {
        spacingHor = sizeY / compsHor;
        for(i = [1 : compsHor - 1]) {
            translate([0, spacingHor * i, 0]) cube([sizeX, wallThickness, dividerWallHeight]);
        }
    }
}

module lid(sizeX, sizeY, wallThickness, wallHeight, fitment, lidSides) {
    // Translate the position of the whole lid to be next to the box
    translate([-sizeX - 20, 0, 0]) {
        // Lid
        cube([sizeX + fitment, sizeY + fitment, wallThickness]);
        
        // Sides
        
        // West
        translate([-wallThickness, -wallThickness, 0]) cube([sizeX + wallThickness + fitment, wallThickness, lidSides]);
        
        // South
        translate([sizeX, -wallThickness, 0]) cube([wallThickness, sizeY + wallThickness + fitment, lidSides]);
       
        // East
        translate([0, sizeY + fitment, 0]) cube([sizeX + wallThickness + fitment, wallThickness, lidSides]);
        
        // North
        translate([-wallThickness, 0, 0]) cube([wallThickness, sizeY + wallThickness + fitment, lidSides]);
    }
}



$fn = 50;

// User configurable parameters
size_x = 120;
size_y = 180;
wall_thickness = 2;
border_wall_height = 40;
divider_wall_height = 35;
compartments_vertical = 3;
compartments_horizontal = 3;
lid_fitment = 0.1;
lid_sides = 6;

// Assigning user modified params or defaults to constants
SIZE_X = size_x != 120 && size_x <= 250 && size_x >= 10 ? size_x : 120;
SIZE_Y = size_y != 180 && size_y <= 250 && size_y >= 10 ? size_y : 180;
WALL_THICKNESS = wall_thickness != 2 && wall_thickness <= 5 && wall_thickness >= 1 ? wall_thickness : 2;
BORDER_WALL_HEIGHT = border_wall_height != 40 && border_wall_height <= 100 && border_wall_height >= 5 ? border_wall_height : 40;
DIVIDER_WALL_HEIGHT = divider_wall_height != 35 && divider_wall_height <= BORDER_WALL_HEIGHT && divider_wall_height >= 5 ? divider_wall_height : 35;
COMPART_VER = compartments_vertical != 3 && (SIZE_X / compartments_vertical) > WALL_THICKNESS + 2 ? compartments_vertical : 3;
COMPART_HOR = compartments_horizontal != 3 && (SIZE_Y / compartments_horizontal) > WALL_THICKNESS + 2 ? compartments_horizontal : 3;
LID_FITMENT = lid_fitment != 0.1 && lid_fitment >= 0.1 && lid_fitment <= 0.2 ? lid_fitment : 0.1;
LID_SIDES = lid_sides != 6 && lid_sides >= 2 && lid_sides <= 10 ? lid_sides : 6;

// Building the box
base(SIZE_X, SIZE_Y, WALL_THICKNESS);
borderWalls(SIZE_X, SIZE_Y, BORDER_WALL_HEIGHT, WALL_THICKNESS);
dividerWalls(SIZE_X, SIZE_Y, WALL_THICKNESS, DIVIDER_WALL_HEIGHT, COMPART_HOR, COMPART_VER);
lid(SIZE_X, SIZE_Y, WALL_THICKNESS, BORDER_WALL_HEIGHT, LID_FITMENT, LID_SIDES);