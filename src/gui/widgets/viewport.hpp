/*
   Copyright (C) 2012 - 2016 by Mark de Wever <koraq@xs4all.nl>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#ifndef GUI_WIDGETS_VIEWPORT_HPP_INCLUDED
#define GUI_WIDGETS_VIEWPORT_HPP_INCLUDED

#include "gui/core/window_builder.hpp"
#include "gui/widgets/widget.hpp"

namespace gui2
{

// ------------ WIDGET -----------{

namespace implementation
{
struct tbuilder_viewport;
} // namespace implementation

class tgrid;

class tviewport : public twidget
{
	friend struct tviewport_implementation;

public:
	/** @deprecated use the second overload. */
	explicit tviewport(twidget& widget);

private:
	tviewport(const implementation::tbuilder_viewport& builder,
			  const tbuilder_widget::treplacements& replacements);

public:
	static tviewport* build(const implementation::tbuilder_viewport& builder,
							const tbuilder_widget::treplacements& replacements);

	~tviewport();

	/** See @ref twidget::place. */
	virtual void place(const tpoint& origin, const tpoint& size) override;

	/** See @ref twidget::layout_initialise. */
	virtual void layout_initialise(const bool full_initialisation) override;

	/** See @ref twidget::impl_draw_children. */
	virtual void impl_draw_children(surface& frame_buffer,
									int x_offset,
									int y_offset) override;

	/** See @ref twidget::child_populate_dirty_list. */
	virtual void
	child_populate_dirty_list(twindow& caller,
							  const std::vector<twidget*>& call_stack) override;

	/** See @ref twidget::request_reduce_width. */
	virtual void request_reduce_width(const unsigned maximum_width) override;

	/** See @ref twidget::find_at. */
	virtual twidget* find_at(const tpoint& coordinate,
							 const bool must_be_active) override;

	/** See @ref twidget::find_at. */
	virtual const twidget* find_at(const tpoint& coordinate,
								   const bool must_be_active) const override;

	/** See @ref twidget::find. */
	twidget* find(const std::string& id, const bool must_be_active) override;

	/** See @ref twidget::find. */
	const twidget* find(const std::string& id,
						const bool must_be_active) const override;

private:
	/** See @ref twidget::calculate_best_size. */
	virtual tpoint calculate_best_size() const override;

public:
	/** See @ref twidget::disable_click_dismiss. */
	bool disable_click_dismiss() const override;

	/** See @ref twidget::create_walker. */
	virtual iterator::twalker_* create_walker() override;

private:
	twidget& widget_;

	bool owns_widget_;
};

// }---------- BUILDER -----------{

namespace implementation
{

struct tbuilder_viewport : public tbuilder_widget
{
	explicit tbuilder_viewport(const config& cfg);

	twidget* build() const;

	twidget* build(const treplacements& replacements) const;

	tbuilder_widget_ptr widget;
};

} // namespace implementation

// }------------ END --------------

} // namespace gui2

#endif
