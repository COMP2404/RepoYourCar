#ifndef APP_MANAGER
#define APP_MANAGER
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <gtk/gtk.h>
#include "WindowApp.h"
#include "GradAppPage.h"
#include "UnderGradAppPage.h"
#include "GradForm.h"
#include "UnderGradForm.h"
#include "../Model/GradAppData.h"
#include "../Model/UGradAppData.h"
#include "../Model/RelatedOneData.h"
#include "../Model/RelatedTwoData.h"
#include "../Model/WorkExperienceData.h"
#include "../Model/Application.h"

//
//#include <String.h>

using namespace std;
class Control;
class WindowApp;
class GradAppPage;
class UnderGradAppPage;
class UnderGradForm;
class GradForm;
class AppManager{
	public:
		friend class GradAppPage;
		friend class UnderGradAppPage;
		friend class StudentPage;
		friend class AdminWindow;
		friend class Control;
		
		AppManager(bool,WindowApp*);
	private:
		GradAppPage *gradPage;
		UnderGradAppPage *underPage;
		GradForm *gradForm;
		UnderGradForm *underForm;
		
		static void submitGradApp(WindowApp*);
		static void submitUGradApp(WindowApp*);
		static void pushRelOneData();
		static void pushRelTwoData();
		static void pushWorkExpData();
		static void fillInData(Application*, WindowApp*);
		static void fillInUData(Application*, WindowApp*);
		static void cycleApps(bool[], WindowApp*);
		

};
#endif