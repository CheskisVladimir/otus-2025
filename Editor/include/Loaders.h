#pragma once

#include "std_includes.h"

class IDocument;

class ILoader
{
public:
    ILoader()          = default;
    virtual ~ILoader() = default;

    virtual std::unique_ptr<IDocument> load() const = 0;
};

class IFileLoader : public ILoader
{
public:
    IFileLoader() = default;
    std::unique_ptr<IDocument> load() const override;

protected:
    std::string get_file_name() const;
    virtual std::unique_ptr<IDocument> load_from_file(const std::string& file_name) const = 0;
};

class XMLLoader : public IFileLoader
{
public:
    XMLLoader() = default;

protected:
    std::unique_ptr<IDocument> load_from_file(const std::string& file_name) const override;
};

class JSONLoader : public IFileLoader
{
public:
    JSONLoader() = default;

protected:
    std::unique_ptr<IDocument> load_from_file(const std::string& file_name) const override;
};