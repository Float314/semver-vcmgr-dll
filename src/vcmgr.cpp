/* 

========================================================================
Copyright (c) 2026, Float314 (a.k.a. Cyphrixz) and all the Contributors
                    to this project (if any). 

This program is free software: you can redistribute it and/or modify
it under the terms of the **GNU Lesser General Public License** as 
published by the Free Software Foundation, either version 3 of the 
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but **WITHOUT ANY WARRANTY**; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

By using this program, you agree to the License. If you do not
agree to the License, you may cease the use of this software 
immediately.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>
========================================================================

*/

#include "version_control.hpp"
#include "vcmgr.h"


int semver_Major(const char* __version) {
    program_version __v1 = __version;

    return { __v1.major() };
}

int semver_Minor(const char* __version) {
    program_version __v1 = __version;

    return { __v1.minor() };
}

int semver_SubMinor(const char* __version) {
    program_version __v1 = __version;

    return { __v1.subMinor()  };
}

const char* semver_ReleaseType(const char* __version) {
    program_version __v1 = __version;

    std::string __relType__ = __v1.releaseType(); 
    return __relType__.c_str(); // niche
}

int semver_RelTypeVersion(const char* __version) {
    program_version __v1 = __version;

    return __v1.relTypeVersion();
}

bool ver_isGreaterThan(const char* __v1, const char* __v2) {
    program_version __v3 = __v1;

    return __v3 > __v2;
}

bool ver_isLessThan(const char* __v1, const char* __v2) {
    program_version __v3 = __v1;

    return __v3 < __v2;
}

bool ver_isEqualTo(const char* __v1, const char* __v2) {
    program_version __v3 = __v1;

    return __v3 == __v2;
}
