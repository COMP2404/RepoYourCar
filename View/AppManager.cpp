#include "AppManager.h"
AppManager::AppManager(bool grad, WindowApp *theApp){
	if(grad){
		
		theApp->gradAppPage = new GradAppPage();
		theApp->gradAppPage->draw(theApp);
		
		
	}
	else if(!grad){
		theApp->uGradAppPage = new UnderGradAppPage();
		
		
		theApp->uGradAppPage->draw(theApp);
	}
	
	
}
void AppManager::submitGradApp(WindowApp* theApp){
	WindowApp::submitGradApp(theApp);
}
void AppManager::submitUGradApp(WindowApp* theApp){
	WindowApp::submitUGradApp(theApp);
}

void AppManager::fillInData(Application * editApp, WindowApp *theApp){
	theApp->gradAppPage->fillInData(editApp,theApp);
}