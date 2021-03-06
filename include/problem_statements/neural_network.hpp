//  ┌─┬─────┐  ││  CISAT: The Cognitively-Inspired Simulated
//  ├─┼─────┤  ││         Annealing Teams Modeling Framework
//  │ │ McC │  ││  include
//  └─┴─────┘  ││   └─problem_statements
//             ││      └─neural_network.hpp

#if PROBLEM_STATEMENT == NEURAL
#ifndef PROBLEM_STATEMENTS__NEURAL_NETWORK_HPP
#define PROBLEM_STATEMENTS__NEURAL_NETWORK_HPP

#include <iostream>
#include <cmath>
#include "graph.hpp"
#include "../utilities/make_random.hpp"
#include "../utilities/write_x3d.hpp"
#include "../utilities/custom_print.hpp"
#include "../utilities/stats.hpp"

class Solution : public Graph{
public:
    // Constants
    static const unsigned long number_of_move_ops;
    static const unsigned long number_of_objectives;
    static const std::vector<long double> goal;

    // Variables
    std::vector<long double> quality;

    // Functions
    Solution(bool);
    Solution(void);
    void apply_move_operator(int move_type);
    void save_as_x3d(std::string save_to_file);

private:
    // Constants
    static const std::string name;

    // Variables
    int solution_id;
    static int solution_counter;
    std::vector<long double> layers;
    int number_of_samples;
    std::vector<std::vector<long double> > x_sample;
    std::vector<std::vector<long double> > y_sample;

    // Inlet location
    static std::vector< std::map<std::string, long double> > seed_graph_parameters;

    // Functions
    void compute_quality(void);
    void create_seed_graph(void);

    // Move operators for Campbell
    void r1_connect_with_edge(void);          // rule 1: Connect two nodes in adjacent layers with an edge.
    void r2_connect_with_noded_edge(void);    // rule 2: Connects two nodes in non-adjacent layers with a node and two edges.
    void r3_replace_with_noded_edge(void);    // rule 3: Replace connection between two nodes with a node and two edges.
    void r4_add_bypass(void);                 // rule 4: Adds an edge that bypasses an existing node.
    void r5_add_parallel_edge(void);          // rule 5: Adds an edge in parallel with an existing edge
    void r6_add_hidden_node(void);            // rule 6: Add a node in a hidden layer and connect it to adjacent layers.
    void remove_nn_edge(void);                   // McComb rule for a reversable grammar
    void remove_nn_node(void);                   // McComb rule for a reversable grammar

    // Utility functions
    void add_nn_node(bool editable, int type, long double layer);
    void add_nn_edge(int n1, int n2, bool editable);
    std::vector<long double> compute_nn_value(std::vector<long double> inputs);
    void make_samples(void);
    long double compute_mse(void);
    void train_nn(void);

    void add_layer(long double L);
    bool is_valid(void);
};

#endif
#endif