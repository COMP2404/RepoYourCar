#ifndef UGRAD_ERROR_CHECK
#define UGRAD_ERROR_CHECK
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "UGradAppData.h"


using namespace std;


class UGradErrorCheck{
	public:
		UGradErrorCheck();
		friend class UnderGradAppPage;
	private:
		bool check(UGradAppData*);
		
		
		
};
#endif