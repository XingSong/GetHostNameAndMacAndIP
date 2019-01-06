#ifndef _HOSTNAME_INFO_H_
#define _HOSTNAME_INFO_H_

#include <string>

//��������
class HostNameInfo
{
public:
	static HostNameInfo* getInstance();
	~HostNameInfo();

	//��ȡ��������
	std::string getHostNameInfo();

	//�����������
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