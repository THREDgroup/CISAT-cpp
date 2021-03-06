//  ┌─┬─────┐  ││  CISAT: The Cognitively-Inspired Simulated
//  ├─┼─────┤  ││         Annealing Teams Modeling Framework
//  │ │ McC │  ││  src
//  └─┴─────┘  ││   └─agents_and_teams
//             ││      └─multiple_teams.cpp

#include "../../include/agents_and_teams/multiple_teams.hpp"

// This does the things, and initializes parameters from file
MultipleTeams::MultipleTeams(ParameterSet x){
    // Save the parameters
    parameters = x;

    // Initialize the best solution vector
    best_solution.assign(Solution::number_of_objectives*parameters.n_reps*parameters.n_agents, std::vector<long double> (parameters.max_iter/parameters.n_agents, 0.0));
    final_solutions.assign(parameters.n_reps*parameters.n_agents, std::vector<long double> (Solution::number_of_objectives, 0.0));
}

// This does the things, and initializes parameters from file
MultipleTeams::MultipleTeams(std::string file_name){
    // Read from a file
    parameters.set_from_file(file_name);

    // Initialize the best solution vector
    best_solution.assign(Solution::number_of_objectives*parameters.n_reps*parameters.n_agents, std::vector<long double> (parameters.max_iter/parameters.n_agents, 0.0));
    final_solutions.assign(parameters.n_reps*parameters.n_agents, std::vector<long double> (Solution::number_of_objectives, 0.0));
}

//// This actually solves the problem LOTS of times.
std::vector<std::vector<long double> > MultipleTeams::solve(void){
    // Assign an id for the run
    id = static_cast <unsigned long> (time(0));

    // Make a new folder for team results
    if(parameters.save_designs >= 1){
        char directory_name[50];
        std::sprintf(directory_name, "./data/%lu/", id);
        mkdir(directory_name, ACCESSPERMS);
    }

    // Do the run
    for(int i = 0; i< parameters.n_reps; i++) {

        // Instantiate a new team
        Team this_team(parameters);
        this_team.run_id = id;
        this_team.team_id = i;

        // Give the team a new start
        this_team.new_start();

        // Solve the problem with the team
        this_team.solve();

        // Save results from the team
        for(int j=0; j<Solution::number_of_objectives; j++){
            for(int k=0; k<parameters.n_agents; k++) {
//                best_solution[Solution::number_of_objectives*i + j] = this_team.best_solution[j];
                best_solution[j + k*Solution::number_of_objectives + (Solution::number_of_objectives*parameters.n_agents)*i] = this_team.best_solution[j + k*Solution::number_of_objectives ];
            }
        }

        // Save the team's best results
//        for(int j=0; j<Solution::number_of_objectives; j++){
//            for(int k=0; k<parameters.n_agents; k++) {
//                final_solutions[i][j] = best_solution[Solution::number_of_objectives * i + j].back();
//            }
//        }
    }

    return final_solutions;
}
