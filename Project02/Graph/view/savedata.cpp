#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cgicc;     // Or reference as cgicc::Cgicc formData; below in object instantiation.

int main(int argc, char **argv)
{
	try {
		Cgicc formData;
		string node1, node2;

		form_iterator fvalue1 = formData.getElement("node1");
		if (!fvalue1->isEmpty() && fvalue1 != (*formData).end()) {
			node1 = **fvalue1;

		}
		else
			cout << "No text entered for value1" << endl;

		form_iterator fvalue2 = formData.getElement("node2");
		if (!fvalue2->isEmpty() && fvalue2 != (*formData).end()) {
			node2 = **fvalue2;
		}
		else
			cout << "No text entered for value2" << endl;

	}
	catch (exception& e) {
		// handle any errors here.
		cout << "ERROR!!" << endl;
	}
	return 0;   // To avoid Apache errors.
}