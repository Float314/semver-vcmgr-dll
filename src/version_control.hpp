/* 

=========================================================================

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

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

/// @brief Version Info, Major, minor, etc.
struct VersionInfo {
    int major{};
    int minor{};
    int subMinor{};
    std::string releaseType;
    int relTypeVersion{};
};

/*
    Program Version Info Class. Use it like this - 
    `program_version ver = "v1.0.9-beta-4";` where v1.0.9-beta-4 is version you wanna specify 

    Part of the "semver-vcmgr" Library.

    Go to https://github.com/Float314/semver-vcmgr for details.

    Copyright (C) 2026, Float314 and contributors. 
*/
class program_version {
private:
    VersionInfo v;
    std::vector<std::string> parts; // niche :/

    void splitData(const std::string& input) {
        parts.clear(); // clear any unused junk data if 
        std::string raw = input;

        std::replace(raw.begin(), raw.end(), '-', '.'); // replace every "-" with "." so we have only one dillemer to worry abt

        // nremove the "v" at start if it contains any :/
        if (!raw.empty() && raw[0] == 'v') {
            raw.erase(0, 1);
        }

        // lol idek what this shi does
        std::stringstream ss(raw);
        std::string segment;
        while (std::getline(ss, segment, '.')) {
            parts.push_back(segment); // split data into the vector.
        }
    }

    /// @brief Assigns the Vectored info in the std::vector<>, converts major, minor and integer related thingys to int.
    void assignData() {
        if (parts.size() >= 1) v.major = std::stoi(parts[0]);
        if (parts.size() >= 2) v.minor = std::stoi(parts[1]);
        if (parts.size() >= 3) v.subMinor = std::stoi(parts[2]);
        if (parts.size() >= 4) v.releaseType = parts[3];
        if (parts.size() >= 5) v.relTypeVersion = std::stoi(parts[4]);
    }

    /// @brief Parse Version String
    /// @param ver std::string version
    /// @return std::vector [major, minor, subMinor, releaseType, relTypeVersion]
    static VersionInfo parseVersionString(const std::string& ver) {
        VersionInfo result;
        std::string raw = ver;

        std::replace(raw.begin(), raw.end(), '-', '.'); // replace every "-" with "." so we have only one dillemer to worry abt/

        // remove the "v" as in "v1.0.1-beta-3" if present
        if (!raw.empty() && raw[0] == 'v') {
            raw.erase(0, 1);
        }

        std::stringstream ss(raw);
        std::string segment;
        std::vector<std::string> p;
        while (std::getline(ss, segment, '.')) {
            p.push_back(segment);
        }

        if (p.size() >= 1) result.major = std::stoi(p[0]);
        if (p.size() >= 2) result.minor = std::stoi(p[1]);
        if (p.size() >= 3) result.subMinor = std::stoi(p[2]);
        if (p.size() >= 4) result.releaseType = p[3];
        if (p.size() >= 5) result.relTypeVersion = std::stoi(p[4]);

        return result;
    }

public:
    std::string rawVersion;

    // set this function as default
    program_version() = default;

    program_version(const std::string& ver) {
        setProjVersion(ver);
    } // hehe

    program_version(const char* ver) {
        setProjVersion(std::string(ver));
    } // what the fuck did AI Review do

    /// @brief Set and parse Project Info
    /// @param inp Input String
    void setProjVersion(const std::string& inp) {
        rawVersion = inp;
        splitData(inp);
        assignData();
    } // nuh uh 

    /*
        Remember a while back i said that you can just version.major(); ? well, this is the implementation :/ 
    */

    /// @brief Major Version of the version
    /// @return An integer, the major number
    int major() const { return v.major; }

    /// @brief Minor Version Number
    /// @return Integer that is the minor version
    int minor() const { return v.minor; }

    /// @brief SubMinor / Patch Version
    /// @return Integer that is the Subminor/Patch No.
    int subMinor() const { return v.subMinor; }

    /// @brief Release Type (Alpha, Beta, Pre-release etc.)
    /// @return `std::string` releaseType. 
    std::string releaseType() const { return v.releaseType; }

    /// @brief Release type patch No. (Like v1.0.9-beta-5, the 5)
    /// @return An Integer that is the Alpha/Beta (smth idek :/ )
    int relTypeVersion() const { return v.relTypeVersion; }

    /*
    And remember a while back i said that you can

    if(versionNo >= "v1.0.9") {do smth} ? 
    Well, this is the implementation
    
    */

    /// @brief Operator <= to Compare Version Info
    /// @param otherVersion Other Version
    /// @return True or False based on the comparison
    bool operator<=(const std::string& otherVersion) const {
        VersionInfo oth = parseVersionString(otherVersion);
        if (v.major != oth.major) return v.major < oth.major;
        if (v.minor != oth.minor) return v.minor < oth.minor;
        return v.subMinor <= oth.subMinor;
    }

    /// @brief Operator >= to Compare Version Info
    /// @param otherVersion Other Version
    /// @return True or False based on the comparison
    bool operator>=(const std::string& otherVersion) const {
        VersionInfo oth = parseVersionString(otherVersion);
        if (v.major != oth.major) return v.major > oth.major;
        if (v.minor != oth.minor) return v.minor > oth.minor;
        return v.subMinor >= oth.subMinor;
    }

    /// @brief Operator == to Compare Version Info
    /// @param otherVersion Other Version
    /// @return True or False based on the comparison
    bool operator==(const std::string& otherVersion) const {
        VersionInfo oth = parseVersionString(otherVersion);
        return v.major == oth.major && v.minor == oth.minor && v.subMinor == oth.subMinor;
    }

    /// @brief Operator != to Compare Version Info
    /// @param otherVersion Other Version
    /// @return True or False based on the comparison
    bool operator!=(const std::string& otherVersion) const {
        return !(*this == otherVersion);
    }

    // need code refining maybe ---------------------------------

    /// @brief Operator < to Compare Version Info
    /// @param otherVersion Other Version
    /// @return True or False based on the comparison
    bool operator<(const std::string& otherVersion) const {
        VersionInfo oth = parseVersionString(otherVersion);
        if(v.major < oth.major) return true;
        else if(v.major > oth.major) return false;

        return(v.subMinor < oth.subMinor);
    }

    /// @brief Operator > to Compare Version Info
    /// @param otherVersion Other Version
    /// @return True or False based on the comparison
    bool operator>(const std::string& otherVersion) const {
        VersionInfo oth = parseVersionString(otherVersion);
        if(v.major > oth.major) return true;
        else if(v.major < oth.major) return false;

        return(v.subMinor > oth.subMinor);
    }
};
// end (maybe)

// change - __programVersionInfo() removed, added in vcmgr.h