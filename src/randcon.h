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

#ifndef __RANDCON_H__
#define __RANDCON_H__

#include <vector>
#include <string>
#include <fstream>
#include <memory>

using std::vector;
using std::string;
using std::ofstream;
using std::unique_ptr;

class RandCon {
private:
    vector<string> inputFiles;
    unique_ptr<ofstream> output;
    unsigned long outLines;

public:
    explicit RandCon(const vector<string>& input);
    RandCon(const RandCon& randCon) = delete;
    RandCon(RandCon&& randCon) = delete;

    ~RandCon();

    RandCon& operator=(const RandCon& randCon) = delete;
    RandCon& operator=(RandCon&& randCon) = delete;

    void setOutputFile(const string& filename);
    void selectMaxLines(unsigned long lines) { outLines = lines; }

    bool run();
};

#endif // __RANDCON_H__
