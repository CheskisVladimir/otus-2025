/// \file main.cpp
/// \brief Function implementations

#include "lib.h"

#include <iostream>
#include "include/all_Includes.h"

int main(int, char **)
{
	std::cout << "Editor  " << version() << std::endl;

	Controller controller;
	ActionFactory factory;
	controller.init_actions(factory);
	auto &view = controller.get_view();
	view.show(controller.get_document());

	Message create(MessageType::create);
	view.notify_сontroller(create);

	Message load(MessageType::load_xml);
	view.notify_сontroller(load);

	Message save(MessageType::save_json);
	view.notify_сontroller(save);

	auto ch = std::make_shared<CharPrimitive>('A');
	controller.get_context().set_primitive(ch->weak_from_this());
	controller.get_context().set_selection({0, 1});
	Message add(MessageType::add_primitive);
	view.notify_сontroller(add);

	controller.get_context().set_selection({20, 21});
	Message del(MessageType::del_primitive);
	view.notify_сontroller(del);
	return 0;
}

///   Controller

Controller::Controller() : IController()
{
	m_document = std::make_unique<Document>();
	m_view = std::make_unique<View>();
	m_view->set_controller(weak_from_this());
	m_context = std::make_unique<Context>();
}

bool Controller::process_message(const IMessage &msg)
{
	auto *action = get_action(msg);
	if (action == nullptr)
	{
		return false;
	}
	if (action->execute(msg, *m_context, *m_document))
		refresh_view();
	return true;
}

const IDocument &Controller::get_document() const { return *m_document; }

IAction *Controller::get_action(const IMessage &msg) const
{
	size_t pos = static_cast<size_t>(msg.get_type());
	if (pos < m_actions.size())
		return m_actions[pos].get();
	return nullptr;
}

void Controller::init_actions(const IActionFactory &factory)
{
	for (size_t msg_pos = 0; msg_pos < m_actions.size(); msg_pos++)
	{
		auto mgs_type = static_cast<MessageType>(msg_pos);
		m_actions[msg_pos] = std::move(factory.create(mgs_type));
	}
}

IContext &Controller::get_context() { return *m_context; }
const IContext &Controller::get_context() const { return *m_context; }

void Controller::refresh_view() const { m_view->show(*m_document); }

IView &Controller::get_view() { return *m_view; }
const IView &Controller::get_view() const { return *m_view; }

/// View

void View::set_controller(std::weak_ptr<IController> controller) { m_controller = controller; }

void View::show(const IDocument &) {}

void View::notify_сontroller(const IMessage &msg) const
{
	auto controller = m_controller.lock();
	if (controller == nullptr)
	{
		// DO SOMETHING
	}

	if (!controller->process_message(msg))
	{
		// DO SOMETHING
	}
}

std::unique_ptr<IAction> ActionFactory::create(MessageType msg_type) const
{
	switch (msg_type)
	{
	case MessageType::create:
		return std::make_unique<CreateDocumentAction>();
		// ...
	default:
		break;
	};
	return nullptr;
}

// Actions
bool CreateDocumentAction::execute(const IMessage &, IContext &, IDocument &)
{
	return true;
}

bool SaveXMLAction::execute(const IMessage &, IContext &, IDocument &)
{
	return true;
}

bool SaveJsonAction::execute(const IMessage &, IContext &, IDocument &)
{
	return true;
}

bool LoadXMLAction::execute(const IMessage &, IContext &, IDocument &)
{
	return true;
}

bool LoadJsonAction::execute(const IMessage &, IContext &, IDocument &)
{
	return true;
}

bool AddPrimitiveAction::execute(const IMessage &, IContext &, IDocument &)
{
	return true;
}

bool DelPrimitiveAction::execute(const IMessage &, IContext &, IDocument &)
{
	return true;
}

//------------------

CharPrimitive::CharPrimitive(char ch)
{
	m_char = ch;
}

char CharPrimitive::get_value() const
{
	return m_char;
}

ShapePrimitive::ShapePrimitive(const std::string &shape_type)
{
	m_type = shape_type;
}

const std::string &ShapePrimitive::get_type() const
{
	return m_type;
}

///////////// Context

Context::Context()
	: m_selection{0, 0}
{
}

void Context::set_selection(const selection_t &selection)
{
	m_selection = selection;
}

IContext::selection_t Context::get_selection() const
{
	return m_selection;
}

const IPrimitive *Context::get_primitive() const
{
	if (auto sp = m_primitive.lock())
	{
		return sp.get();
	}
	return nullptr;
}

void Context::set_primitive(const std::weak_ptr<const IPrimitive> &b)
{
	m_primitive = b;
}