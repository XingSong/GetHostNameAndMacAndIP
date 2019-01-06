#ifndef _HOSTNAME_INFO_H_
#define _HOSTNAME_INFO_H_

#include <string>

//本机名称
class HostNameInfo
{
public:
	static HostNameInfo* getInstance();
	~HostNameInfo();

	//获取本机名称
	std::string getHostNameInfo();

	//输出本机名称
	void showHostNameInfo();

	class GC
	{
	public:
		~GC();
	};
private:
	HostNameInfo();
	static HostNameInfo* m_Instance;
};

#endif	//_HOSTNAME_INFO_H_