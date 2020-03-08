A generator for random instances of Distributed Constraint Optimization Problems.

dcop-generator <nb_instances> <outfile> <instance>
	where:
	  <nb_instances> = the number of instances to generate
	  <outfile>      = the output filename (will be numbered)
	  <instance>     =  -random | -scale-free | -grid 

	-random      nb_agents domain_size p1 p2
			[max_nb_neighbors[=nb_agents] max_constr_arity[=2]  nb_local_variables[=1] max_nb_boundary_variables[=1] p1_local_variables[=1.0]]
	-scale-free  nb_agents domain_size lambda[=1.5] p2 max_nb_neighbors
			 [max_constr_arity[=2]  nb_local_variables[=1] max_nb_boundary_variables[=1] p1_local_variables[=1.0]]
	-grid        nb_agents domain_size p2 
			[max_constr_arity[=2] max_nb_neighbors[=4] nb_local_variables[=1] max_nb_boundary_variables[=1] p1_local_variables[=1.0]]
	-meeting-scheduling  nb_agents domain_size p1 p2# dcop_generator_pdcdcop
