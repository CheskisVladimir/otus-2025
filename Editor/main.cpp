/**
 * @brief Provides stuff for my great program.
 */

#include "lib.h"

#include <iostream>
#include "include/all_Includes.h"

/*!
	\brief  Не неёт никакой смысловой нагрузки

*/
/// Краткое описание
int main(int, char **)
{
	std::cout << "Version: " << version() << std::endl;
	std::cout << "It's Editor" << std::endl;
	std::cout << "i'm" << std::endl;

	return 0;
}

Editor::Editor(std::unique_ptr<IVewer> &&viewer, std::unique_ptr<IController> &&controller)
{
	m_controller = std::move(controller);
	m_viewer = std::move(viewer);
	m_current_document = std::make_unique<EmptyDocument>();
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

/**
	Processes a message
	\param[in] message message
	\param[out] document document
	\return returns true, if the document was changed
*/

bool ControllerWithActions::process_message(const IMessage &message, IDocument &document)
{
	auto *action = get_action(message);
	if (action == nullptr)
		return false;
	return action->perform(message, *m_context, document);
}
