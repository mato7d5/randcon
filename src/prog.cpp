/*
Copyright 2018 Martin Mancuska <mmancuska@gmail.com>
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 3,
as published bythe Free Software Foundation.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along
with this program; if not, write to the
Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "randcon.h"
#include <iostream>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

namespace po = boost::program_options;

int main(int argc, char** argv) {
    po::options_description desc("Allowed command line arguments:");
    desc.add_options()
    ("help", "Show help message.")
    ("input", po::value<vector<string>>()->multitoken(), "Input files.")
    ("output", po::value<string>(), "Output file. Default is standard output.")
    ("lines", po::value<unsigned long>()->implicit_value(0), "Choose only given number of lines. Default all lines.");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help")) {
        std::cout << desc << '\n';
        return 1;
    }

    if (!vm.count("input")) {
        std::cout << "No input files.\n" << desc << '\n';
        return 1;
    }

    RandCon rc(vm["input"].as<vector<string>>());

    if (vm.count("output")) {
        rc.setOutputFile(vm["output"].as<string>());
    }

    if (vm.count("lines")) {
        rc.selectMaxLines(vm["lines"].as<unsigned long>());
    }

    if (!rc.run()) {
        std::cerr << "Error.\n";
        return -1;
    }

    return 0;
}
