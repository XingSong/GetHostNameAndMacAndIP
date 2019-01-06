#ifndef _NETWORK_INFO_H_
#define _NETWORK_INFO_H_

//网卡配置、IP信息
class NetWorkInfo
{
public:
	static NetWorkInfo* getInstance();
	~NetWorkInfo();

	//输出网卡信息
	void showNetWorkInfo();

	class GC
	{
	public:
		~GC();
	};
private:
	NetWorkInfo();
	static NetWorkInfo* m_Instance;
};
#endif	//_NETWORK_INFO_H_
