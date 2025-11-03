/**
 * @brief Provides stuff for my great program.
 */

#include "lib.h"

#include <iostream>
#include "include/all_Includes.h"

int main(int, char **)
{
	std::cout << "Version: " << version() << std::endl;
	std::cout << "It's Editor" << std::endl;
	std::cout << "i'm" << std::endl;

	return 0;
}

// Actions
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

std::pair<size_t, size_t> SimpleSelection::get() const
{
	return m_selection;
}

void SimpleSelection::set(const std::pair<size_t, size_t> &pos) { m_selection = pos; }

///   Controller

Controller::Controller() : IController()
{
	// m_document = create doc
	// m_vew = create view
	m_view->set_controller(weak_from_this());
	// m_context = create_context
}

void Controller::process_message(const IMessage &msg)
{
	auto *action = get_action(msg);
	if (action == nullptr)
	{
		// DO SOMETHING
	}
	if (action->execute(msg, *m_context, *m_document))
		refresh_view();
}

const IDocument &Controller::get_document() const { return *m_document; }

IAction *Controller::get_action(const IMessage &) const
{
	return nullptr;
}

void Controller::refresh_view() const { m_view->show(*m_document); }

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
	controller->process_message(msg);
}