#include <Python.h>

// {{{
void _p(PyObject *target)
{ 
	PyObject_Print(
			target,
			stdout,
			Py_PRINT_RAW);
	std::cout << std::endl;
}

int main()
{
	Py_Initialize();
	PyObject *p = PyImport_ImportModule("compiler");
	PyObject *parse_func = PyObject_GetAttrString(p,"parse");
	PyObject *str = PyString_FromString("x = 10+5"); 
	PyObject *tuple = PyTuple_Pack(1,str);
	PyObject *ast = PyObject_Call(parse_func,tuple,NULL);
	// PyObject_Print( ast ,stdout,Py_PRINT_RAW);
	ast = PyObject_Call( 
			PyObject_GetAttrString(ast,"getChildren"),
			PyTuple_Pack(0,NULL),NULL);
	// PyObject_Print( ast ,stdout,Py_PRINT_RAW);

	// PyObject_Print( 
	// 		PyObject_GetItem( ast, PyInt_FromLong(1) ),
	// 		stdout,
	// 		Py_PRINT_RAW);

	// _p( PyObject_GetItem(ast, PyInt_FromLong(1) ) );
	// _p(PyObject_GetAttrString(PyObject_GetAttrString(p,"ast") ,"Stmt"));
	std::cout << PyObject_IsInstance(
			PyObject_GetItem(ast, PyInt_FromLong(1) ),
			PyObject_GetAttrString(
				PyObject_GetAttrString(p,"ast") ,
				"Stmt"));
					
			
	Py_Finalize(); 
	return 0;
}
// }}}
