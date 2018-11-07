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

#include "MemoryMappedInputFile.h"
#include <utility>

//ctor
MemoryMappedInputFile::MemoryMappedInputFile(const string& fileName) {
    fileMapping = std::make_unique<bi::file_mapping> (fileName.c_str(), bi::read_only);
    mappedRegion = std::make_unique<bi::mapped_region> (*fileMapping, bi::read_only);
}

//dtor
MemoryMappedInputFile::~MemoryMappedInputFile() {

}

//methods
size_t MemoryMappedInputFile::getLines(vector<string>& lines) {
    char ch = ' ';
    char* address = static_cast<char*> (mappedRegion->get_address());

    lines.clear();
    string line;
    auto fileSize = mappedRegion->get_size();
    for (size_t i = 0; i < fileSize; ++i) {
        ch = static_cast<char> (*(address++));
        
        if (ch != '\n') 
            line.push_back(ch);
        else {
            lines.push_back(std::move(line));

            // skip '\r' if needed
            ch = static_cast<char> (*address);
            if (ch == '\r')
                ++address;
        }
    }

    return lines.size();
}
