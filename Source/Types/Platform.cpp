#include "Platform.hpp"

#include <iostream>
#include "../Util.hpp"

bool Platform::Parse(const YAML::Node &node) {
    if (node["Name"]) {
        m_Name = node["Name"].as<std::string>();
    }
    else {
        Util::PrintYAMLError("Platform missing name.", node);
        return false;
    }

    if (node["Variables"]) {
        for (auto sub : node["Variables"]) {
            for (auto var : sub) {
                std::string name = var.first.as<std::string>();
                std::string value = var.second.as<std::string>();
                m_Variables[name] = value;
            }
        }
    }

    return true;
}