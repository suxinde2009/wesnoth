/*
 Part of the Battle for Wesnoth Project http://www.wesnoth.org/
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY.
 
 See the COPYING file for more details.
 */

#ifndef LUA_FORMULA_BRIDGE_HPP_INCLUDED
#define LUA_FORMULA_BRIDGE_HPP_INCLUDED

#include <string>
#include <boost/shared_ptr.hpp>

struct lua_State;

class variant;
namespace game_logic {
	class formula;
	class function_symbol_table;
	class formula_debugger;
	class formula_callable;
}

namespace lua_formula_bridge {
	
	int intf_eval_formula(lua_State*);
	int intf_compile_formula(lua_State*);
	std::string register_metatables(lua_State*);
	
	class fwrapper {
		boost::shared_ptr<game_logic::formula> formula_ptr;
	public:
		fwrapper(const std::string& code, game_logic::function_symbol_table* functions = nullptr);
		std::string str() const;
		variant evaluate(const game_logic::formula_callable& variables, game_logic::formula_debugger* fdb = nullptr) const;
	};
	
} // end namespace lua_formula_bridge

#endif
