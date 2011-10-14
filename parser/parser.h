#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <Python.h>
#include <string>
class Parser
{
	private: 
		// Whole source code in PyList form
		PyObject *whole_code; 
		// Compiler module
		PyObject *mod_compiler;
		// current line (for next() )
		unsigned int current_line ;

	public: 
		Parser(const std::string &source);
		~Parser(); 
		// get the number of executing lines 
		unsigned int get_line_max();
		// yield Node at next line
		PyObject *next();
};
#endif
