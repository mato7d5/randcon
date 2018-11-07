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

#ifndef __MEMORYMAPPEDINPUTFILE_H__
#define __MEMORYMAPPEDINPUTFILE_H__

#include "InputFile.h"
#include <memory>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/file_mapping.hpp>

using std::unique_ptr;
namespace bi = boost::interprocess;

class MemoryMappedInputFile : public InputFile {
private:
    unique_ptr<bi::file_mapping> fileMapping;
    unique_ptr<bi::mapped_region> mappedRegion;

public:
    explicit MemoryMappedInputFile(const string& fileName);
    virtual ~MemoryMappedInputFile();

    size_t getLines(vector<string>& line) override; 
};

#endif // __MEMMORYMAPPEDINPUTFILE_H__
