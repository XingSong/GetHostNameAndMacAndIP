#include "HostNameInfo/HostNameInfo.h"
#include "NetWorkInfo/NetWorkInfo.h"
#include <cstdlib>

void main()
{
	HostNameInfo::getInstance()->showHostNameInfo();
	NetWorkInfo::getInstance()->showNetWorkInfo();

	system("pause");
}