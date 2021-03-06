#ifndef UTILITIES__WRITE_VRML_HPP
#define UTILITIES__WRITE_VRML_HPP

#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class WriteX3D {
public:
    // Constructor
    WriteX3D(void);

    // Open and close file
    void open_file(std::string file_path);
    void start_scene(long double x, long double y, long double z);
    void close_scene(void);
    void close_file(void);

    // HMTL Objects
    void add_html(std::string tag, std::string text);

    // Writing objects in the scene
    void write_sphere(long double x, long double y, long double z, long double radius);
    void write_line(long double x1, long double y1, long double z1, long double x2, long double y2, long double z2, int size);

private:
    std::ofstream my_file;

};


#endif