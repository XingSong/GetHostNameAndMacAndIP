#include "HostNameInfo.h"
#include <WinSock2.h>
#include <iostream>
#pragma comment(lib, "WS2_32.lib")//全局数据

using namespace std;

#define  CC_SAFE_DELETE(p) do {if(p){delete (p);p = NULL;}} while (0)

HostNameInfo::HostNameInfo()
{
}

HostNameInfo* HostNameInfo::m_Instance = new HostNameInfo();

HostNameInfo* HostNameInfo::getInstance()
{
	return m_Instance;
}

HostNameInfo::~HostNameInfo()
{
}

//获取本机名称
std::string HostNameInfo::getHostNameInfo()
{
	char buf[256] = "";
	struct hostent* ph = nullptr;
	WSADATA w;
	WSAStartup(MAKEWORD(2, 0), &w);
	gethostname(buf, 256);
	std::string hostName = buf;	//此处获得本机名称
	return hostName;
}

//输出本机名称
void HostNameInfo::showHostNameInfo()
{
	cout << "本机名称：" <<getHostNameInfo().c_str() << endl;
	cout << "*****************************************************" << endl;
}

HostNameInfo::GC::~GC()
{
	CC_SAFE_DELETE(m_Instance);
}
