#include "parser.h"
#include <cstdio>
#include <iostream>

// --------------------------------------------------
// Public field
// --------------------------------------------------
Parser::Parser( const std::string &source) : current_line(0)
{
	// initialize Python interpreter
	Py_Initialize();

	// invoke parser and parse given source code
	mod_compiler= 
		PyImport_ImportModule("compiler");
	PyObject* parser = 
		PyObject_GetAttrString( mod_compiler, "parse");
	// Create argument from given "source"
	PyObject* pystr_args =
		PyString_FromString( source.c_str() );
	PyObject* pytuple_args =
		PyTuple_Pack(1,pystr_args);
	// Invoke compiler.parse with created pytuple_args
	whole_code = 
		PyObject_Call( 
			PyObject_Call(parser,pytuple_args,NULL), // Module
			PyTuple_Pack(0,NULL),NULL); 

	return;
}

Parser::~Parser()
{
	// deallocate Python interpreter
	Py_Finalize();
}

unsigned int Parser::get_line_max()
{ 
	return PyObject_Length(whole_code);
}

PyObject *Parser::next()
{ 
	if (current_line <= get_line_max() )
	{
		PyObject *result = PyObject_GetItem(
															whole_code,
															PyInt_FromLong(current_line)); 
		++current_line;
		return result;
	}else
	{
		return NULL;
	}
}

// --------------------------------------------------
// Private Field
// --------------------------------------------------
