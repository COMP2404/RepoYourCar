#ifndef GRAD_ERROR_CHECK
#define GRAD_ERROR_CHECK
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "GradAppData.h"


using namespace std;


class GradErrorCheck{
	public:
		GradErrorCheck();
		friend class GradAppPage;
		
	private:
		bool check(GradAppData*);
		
		
		
};
#endif