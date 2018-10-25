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
#include "MemoryMappedInputFile.h"

#include <filesystem>
#include <memory>
#include <iostream>
#include <random>
#include <fstream>
#include <algorithm>
#include <functional>
#include <utility>

using std::filesystem::path;
using std::make_unique;
using std::cerr;
using std::cout;
using std::random_device;
using std::mt19937;
using std::ifstream;
using std::shuffle;
using std::reference_wrapper;

// ctor
RandCon::RandCon(const vector<string>& input) {
    inputFiles = input;
    output = nullptr;
    outLines = 0;
}

// dtor
RandCon::~RandCon() {
    if (output) {
        output->close();
    }
}

// methods
void RandCon::setOutputFile(const string& filename) {
    if (output) {
        output->close();
        output.reset(nullptr);
    }

    path p(filename);
    output = make_unique<ofstream>(p, std::ios::trunc | std::ios::out);
}

bool RandCon::run() {
    if (inputFiles.empty()) {
        cerr << "No input files.\n";
        return false;
    }

    vector<string> allLines;

    string line;
    for (const auto& file : inputFiles) {
        MemoryMappedInputFile inputFile(file);
        vector<string> fileLines;
        
        if (inputFile.getLines(fileLines) > 0) 
            allLines.insert(allLines.end(), fileLines.begin(), fileLines.end());
    } 

    random_device rd;
    auto mtgen = mt19937(rd());

    shuffle(allLines.begin(), allLines.end(), mtgen);

    std::ostream& outStream = output ? *output : cout;
    if (outLines > 0) {
        vector<reference_wrapper<string>> selectedLines(allLines.begin(), allLines.begin() + outLines);
    
        for (const auto& line : selectedLines) {
            outStream << line.get() << '\n';
        }
    }
    else {
        for (const auto& line : allLines) {
            outStream << line << '\n';
        }
    }

    return true;   
}