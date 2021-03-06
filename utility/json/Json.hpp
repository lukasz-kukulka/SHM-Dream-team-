#pragma once
#include <nlohmann/json.hpp>

class JsonSerializer;

class Json {
public:
    Json() = default;
    Json(const nlohmann::json& json);

    size_t getBlockArraySize(const std::string& blockName) const;
    size_t getArraySize() const;

    template <typename T>
    T getValue(const std::string& name) const {
        return json.at(name).get<T>();
    }

    template <typename T>
    T getArrayValue(size_t index, const std::string& name) const {
        return json.at(index).at(name).get<T>();
    }

    template <typename T>
    T getBlockValue(const std::string& blockName, const std::string& name) const {
        return json.at(blockName).at(name).get<T>();
    }

    template <typename T>
    T getBlockArrayValue(const std::string& blockName, size_t index, const std::string& name) const {
        return json.at(blockName).at(index).at(name).get<T>();
    }

    template <typename T>
    void putValue(const std::string& name, const T& value) {
        json[name] = value;
    }

    template <typename T>
    void putArrayValue(size_t index, const std::string& name, const T& value) {
        json[index][name] = value;
    }

    template <typename T>
    void putBlockValue(const std::string& blockName, const std::string& name, const T& value) {
        json[blockName][name] = value;
    }

    template <typename T>
    void putBlockArrayValue(const std::string& blockName, size_t index, const std::string& name, const T& value) {
        json[blockName][index][name] = value;
    }

    friend JsonSerializer;

private:
    nlohmann::json json{};
};
