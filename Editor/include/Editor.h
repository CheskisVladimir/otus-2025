#pragma once

#include "std_includes.h"

class IDocument;
class IMessage;
class IController;
class IVewer;
class ILoader;
class ISaver;

class Editor
{

public:
    Editor(std::unique_ptr<IVewer> &&viewer, std::unique_ptr<IController> &&controller);

    const IDocument &get_current_document() const;
    bool process_message(const IMessage &message);
    bool load(const ILoader &loader);

private:
    std::unique_ptr<IDocument> m_current_document;
    std::unique_ptr<IController> m_controller;
    std::unique_ptr<IVewer> m_viewer;
};