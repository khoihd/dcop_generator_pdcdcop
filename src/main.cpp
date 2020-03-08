#include <iostream>

#include "IO/output-xml.hpp"
#include "IO/output-topology.hpp"
#include "IO/output-max_sum.hpp"
#include "IO/output-dalo.hpp"
#include "IO/output-wcsp.hpp"
#include "Instance/instance-factory.hpp"
#include "string_utils.hpp"
#include "IO/input.hpp"

using namespace dcop_generator;
using namespace misc_utils;
using namespace std;


int main(int argc, char* argv[])
{
	input::check_params(argc, argv);

	std::string path_file = input::get_file_out(argv);
	std::string pathout = string_utils::split_path_file(path_file)[0];
	std::string fileout = string_utils::split_path_file(path_file)[1];
	int nb_instances = input::get_nb_instances(argv);

	//output::ptr create_topo = make_shared<output_topology>(pathout, fileout, nb_instances);
	output::ptr create_xml  = make_shared<output_xml>(pathout, fileout, nb_instances);
	output::ptr create_bms  = make_shared<output_maxsum>(pathout, fileout, nb_instances);
	output::ptr create_dalo = make_shared<output_dalo>(pathout, fileout, nb_instances);
	output::ptr create_wcsp = make_shared<output_wcsp>(pathout, fileout, nb_instances);

	for (int i = 0; i < nb_instances; ++i) {
		instance::ptr instance = instance_factory::create(argc, argv);
		// create_topo->to_string( instance );
		create_xml->to_string( instance );
		// create_wcsp->to_string( instance );
		// create_bms->to_string( instance );
		// create_dalo->to_string( instance );
	}

	return 0;
}
