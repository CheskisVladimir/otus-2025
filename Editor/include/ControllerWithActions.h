#pragma once

#include "IController"

class IAction;
class IMessage;
class EditContext;

class ControllerWithActions : public IController
{

public:
    ControllerWithActions();

    bool process_message(const IMessage &message, IDocument &document) override;

protected:
    virtual IAction *get_action(const IMessage &message) const = 0;

private:
    std::unique_ptr<EditContext> m_context;
};
