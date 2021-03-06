#include "../../include/utilities/custom_print.hpp"

//// Save a vector to a file
void save_to_file(std::string file_path, std::vector<long double> x){
    // Open a file stream
    std::ofstream my_file;

    // Open a file on that file stream
    my_file.open(file_path);

    // Set scientific notation. Mostly for nice alignment
    my_file << std::scientific;

    // Step through the vector, and print an element on each line
    for(int i=0; i<x.size(); i++){
        my_file << x[i]  << std::endl;
    }

    // Close the file
    my_file.close();
}


//// Save a vector of vectors to file. This happens a lot, actually.
void save_to_file(std::string file_path, std::vector< std::vector<long double> > x){
    // Open a file stream
    std::ofstream my_file;

    // Open a file on that file stream
    my_file.open(file_path);

    // Set to scientific notation, mostly for alignment
    my_file << std::scientific;

    // Print each sub-vector to a column.
    for(int i=0; i<x[0].size(); i++) {
        for(int j=0; j<x.size(); j++){
            my_file << x[j][i] << "\t";
        }
        my_file << std::endl;
    }

    // Close the file
    my_file.close();
}

//// Save a vector of vectors to file. This happens a lot, actually.
void save_to_file(std::string file_path, std::vector< std::vector< std::vector<long double> > > x){
    // Open a file stream
    std::ofstream my_file;

    // Open a file on that file stream
    my_file.open(file_path);

    // Set to scientific notation, mostly for alignment
    my_file << std::scientific;

    // Print each sub-vector to a column.
    for(int i=0; i<x[0][0].size(); i++) {
        for(int j=0; j<x[0].size(); j++){
            for(int k=0; k<x.size(); k++) {
                my_file << x[k][j][i] << "\t";
            }
            my_file << std::endl;
        }
        my_file << std::endl;
    }

    // Close the file
    my_file.close();
}
