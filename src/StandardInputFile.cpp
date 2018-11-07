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

#include "StandardInputFile.h"
#include <utility>

// ctor
StandardInputFile::StandardInputFile(const string& fileName) {
    inputFile.open(fileName);
}

// dtor
StandardInputFile::~StandardInputFile() {
    if (inputFile.is_open())
        inputFile.close();
}

// methods
size_t StandardInputFile::getLines(vector<string>& lines) {
    if (inputFile.is_open()) {
        string line;
        while (std::getline(inputFile, line)) {
            lines.push_back(std::move(line));
        }

        return lines.size();
    }

    return 0;
}
