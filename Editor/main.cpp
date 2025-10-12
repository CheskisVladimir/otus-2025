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

size_t EditContext::selected_primitive_position() const { return 0; }

bool AddPrimitiveAction::perform(const IMessage &, EditContext &, IDocument &) const
{
	return true;
}

bool RemovePrimitiveAction::perform(const IMessage &, EditContext &, IDocument &) const
{
	return true;
}

ControllerWithActions::ControllerWithActions()
{
	m_context = std::make_unique<EditContext>();
}

bool ControllerWithActions::process_message(const IMessage &message, IDocument &document)
{
	auto *action = get_action(message);
	if (action == nullptr)
		return false;
	return action->perform(message, *m_context, document);
}
