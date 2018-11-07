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

#ifndef __INPUTFILE_H__
#define __INPUTFILE_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

class InputFile {
public:
    InputFile() { }
    virtual ~InputFile() = 0;

    virtual size_t getLines(vector<string> &lines) = 0;
};

#endif // __INPUTFILE_H__
