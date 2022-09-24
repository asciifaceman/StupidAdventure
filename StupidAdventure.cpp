// StupidAdventure.cpp : Defines the entry point for the application.
//

#include "StupidAdventure.h"
#include <drogon/HttpAppFramework.h>
#include <trantor/utils/Logger.h>


int main()
{
	LOG_INFO << "Configuring server";

	LOG_INFO << "Attempting to load config file...";
	try
	{
		// need to make this injectable somehow
		drogon::app().loadConfigFile("../../../config.json");
	}
	catch (const std::exception& e)
	{
		LOG_ERROR << e.what();
		return 1;
	}

	LOG_INFO << "Launching server";
	drogon::app().run();

	LOG_INFO << "All done, exiting";

	return 0;
}
