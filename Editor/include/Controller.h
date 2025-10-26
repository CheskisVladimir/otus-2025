#pragma once

#include "std_includes.h"

class IContext;
class IDocument;
class IView;
class IAction;
class IMessage;

class IController : public std::enable_shared_from_this<IController>
{
private:
    /* data */
public:
    IController(/* args */);
    virtual ~IController() = default;

    virtual const IDocument& get_document() const     = 0;
    virtual void process_message(const IMessage& msg) = 0;
};

class Controller : public IController
{
public:
    Controller();

    virtual const IDocument& get_document() const override;
    virtual void process_message(const IMessage& msg) override;

protected:
    virtual IAction* get_action(const IMessage& message) const;

private:
    void refresh_view() const;
    std::unique_ptr<IDocument> m_document;
    std::unique_ptr<EditContext> m_context;
    std::shared_ptr<IView> m_view;
};
