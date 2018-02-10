#include "main.h"

CClientNetwork	*gNetwork;
CConfiguration  *gConfig;
CGame			*gGame;
CRender			*gRender;
CLogger			*gLog;
CChat			*gChat;

CCore::CCore()
{
#ifdef VCCOOP_DEBUG
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
#endif
	srand(time(NULL));

	gChat = new CChat();
	gLog = new CLogger();
	gLog->Log("[CCore] %s %s loaded.\n", VCCOOP_NAME, VCCOOP_VER);
	gLog->Log("[CCore] Initializing classes.\n");
	gConfig = new CConfiguration();
	gNetwork = new CClientNetwork();
	gGame = new CGame();
	gRender = new CRender();
	gRender->gGuiContainer.push_back(gChat);

	gLog->Log("[CCore] Main method finished.\n");

	MemWrite<s32>(0x9B6CBC, 800);

	Events::gameProcessEvent += [] {
		gGame->Run();
		gRender->Run();
	};
}
CCore::~CCore()
{
	delete gRender;
	gLog->Log("[CCore] CCore shutting down\n");
	delete gLog;
}