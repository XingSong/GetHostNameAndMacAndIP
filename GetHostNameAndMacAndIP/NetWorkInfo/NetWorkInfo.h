#ifndef _NETWORK_INFO_H_
#define _NETWORK_INFO_H_

//�������á�IP��Ϣ
class NetWorkInfo
{
public:
	static NetWorkInfo* getInstance();
	~NetWorkInfo();

	//���������Ϣ
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
