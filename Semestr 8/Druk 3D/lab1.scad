module gear(teeth, step, height=2) {
    angle = 360/(teeth*2);
    radius = (step/2) / sin(angle/2);
    apothem = (step/2) / tan(angle/2);
    module circles() {
        for (i = [1:teeth])
            rotate(i * angle * 2) translate([radius,0,0]) circle(step/2);
    }
    linear_extrude(height) difference() {
        union() {
            circle(apothem);
            circles();
        }
        rotate(angle) circles();
    }
}

// gears
difference() {
    color("blue") translate([0, 0, 3.2]) rotate(85-$t*360/30) gear(30, 5);
    translate([-0.25, -0, 3.2]) cylinder(3.2, 3.2, 3);
}
 
difference() {
    color("red") translate([-64, 0, 3.2]) rotate(15+$t*360/10) gear(10, 5);
    translate([-64,-0, 3.2]) cylinder(3.2, 3.2, 3);
}

// base
translate([-90, -15, 0]) cube([150, 30, 3]);

// centering pin big
translate([-0.25, -0, 3]) cylinder(3, 3, 3);
translate([-0.25, -0, 6]) cylinder(2, 3, 2);

// centering pin small
translate([-64,-0, 3]) cylinder(3, 3, 3);
translate([-64,-0, 6]) cylinder(2, 3, 2);