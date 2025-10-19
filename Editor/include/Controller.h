#include "std_includes.h"

class EditContext;
class IDocument;
class ILoader;
class ISaver;
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
    virtual void create_new()                         = 0;
    virtual void load(const ILoader& loader)          = 0;
    virtual void save(const ISaver& saver)            = 0;
    virtual void process_message(const IMessage& msg) = 0;

    virtual EditContext& get_context()             = 0;
    virtual const EditContext& get_context() const = 0;
};

class Controller : public IController
{
public:
    Controller();

    virtual const IDocument& get_document() const override;
    virtual void create_new() override;
    virtual void load(const ILoader& loader) override;
    virtual void save(const ISaver& saver) override;
    virtual void process_message(const IMessage& msg) override;

    virtual EditContext& get_context() override;
    virtual const EditContext& get_context() const override;

protected:
    virtual IAction* get_action(const IMessage& message) const = 0;

private:
    void refresh_view() const;
    std::unique_ptr<IDocument> m_context;
    std::unique_ptr<EditContext> m_context;
    std::shared_ptr<IView> m_view;
};
