h = 10;
Point(1) = {0, 0, 0, h};
Point(2) = {1, 0, 0, h};
Point(3) = {0, 1, 0, h};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 1};
Line Loop(5) = {3, 1, 2};
Plane Surface(5) = {5};
Physical Point(1) = {1, 2, 3};
Physical Line(1) = {1, 2, 3};
Physical Surface(0) = {5};
