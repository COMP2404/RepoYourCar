#include "AppManager.h"
AppManager::AppManager(bool grad, WindowApp *theApp){
	if(grad){
		
		theApp->editGMode = false;
		theApp->gradAppPage = new GradAppPage();
		theApp->gradAppPage->draw(theApp);
		theApp->gradAppPage->edit = false;
		
	}
	else if(!grad){

		theApp->editUMode = false;
		theApp->uGradAppPage = new UnderGradAppPage();

		theApp->uGradAppPage->draw(theApp);
		theApp->uGradAppPage->edit = false;
	}
	
	
}
void AppManager::submitGradApp(WindowApp* theApp){
	WindowApp::submitGradApp(theApp);
}
void AppManager::submitUGradApp(WindowApp* theApp){
	WindowApp::submitUGradApp(theApp);
}

void AppManager::fillInData(Application * editApp, WindowApp *theApp){
	theApp->editGMode = true;
	theApp->gradAppPage->fillInData(editApp,theApp);
}
void AppManager::fillInUData(Application * editApp, WindowApp *theApp){
	theApp->editUMode = true;
	theApp->uGradAppPage->fillInData(editApp,theApp);
}
void AppManager::cycleApps(WindowApp *theApp){
	Application *app = (*theApp->cycle)[theApp->cycler];
//	if(theApp->cyclerTypes[theApp->cycler]){
		theApp->canEdit = false;
		AppManager *appMan = new AppManager(theApp->cycler,theApp);
		appMan->fillInData(app, theApp);
	//}else{
	//	window->theApp->canEdit = false;
	//	AppManager manager = new AppManager(theApp->cycler,theApp);
	//	appMan->fillInData(app, window->theApp);
	//}
}
void AppManager::nextApp(WindowApp* theApp){
	
	if(theApp->cycler < theApp->cycle->size()){
		cout << "next App" << endl;
		theApp->cycler+=1;
		AppManager::cycleApps(theApp);
	}
	cout<< "cycler index" <<endl;
			cout<< theApp->cycler <<endl;
			cout<< "cycler size" <<endl;
			cout<< theApp->cycle->size() <<endl;
			
}
void AppManager::prevApp(WindowApp* theApp){
	
	if(theApp->cycler > 0){
		cout << "prev App" << endl;
		theApp->cycler -=1;
		AppManager::cycleApps(theApp);
	}
}