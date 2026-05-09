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

#ifndef VCMGR_H
#define VCMGR_H

// Logic to handle export/import symbols
#ifdef EXPORTING_DLL
    #define VCMGR_API __declspec(dllexport)
#else
    #define VCMGR_API __declspec(dllimport)
#endif


extern "C" {
    VCMGR_API int semver_major(const char* __version);
    VCMGR_API int semver_Minor(const char* __version);
    VCMGR_API int semver_SubMinor(const char* __version);
    VCMGR_API const char* semver_ReleaseType(const char* __version);
    VCMGR_API int semver_RelTypeVersion(const char* __version);
    VCMGR_API bool ver_isGreaterThan(const char* __v1, const char* __v2);
    VCMGR_API bool ver_isLessThan(const char* __v1, const char* __v2);
    VCMGR_API bool ver_isEqualTo(const char* __v1, const char* __v2);

    void __programVersionInfo() { 
        std::cout 
            << "semver-vcmgr by Float314 - \n"
            << "Easy to use Semantic Version Manager and comparison Library. Lightweight \n"
            << "And easy to use! Go to <https://github.com/Float314/semver-vcmgr> for \n"
            << "details and to implement it yourself :) \n\n"
            << "Copyright (C) 2026, Float314 and Contributors. Licensed under the GNU LGPL \n"
            << "v3. Free as in Freedom!" << std::endl;
    }

    void __DLLInfo__semver_() {
        std::cout 
            << "Semver-vcmgr DLL by Float314 \n"
            << "Port of semver-vcmgr \n"
            << "Licensed Under the GNU LGPL v3. Free as in Freedom! \n"
            << "Copyright (C) 2026, Float314 and Contributors. Long live Free Software! \n"
            << std::endl;
    }
}

#endif