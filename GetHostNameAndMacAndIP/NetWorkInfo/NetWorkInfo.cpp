#include "NetWorkInfo.h"
#include <WinSock2.h>
#include <Iphlpapi.h>
#include <iostream>
#pragma comment(lib,"Iphlpapi.lib")

using namespace std;

#define  CC_SAFE_DELETE(p) do {if(p){delete (p);p = NULL;}} while (0)

NetWorkInfo::NetWorkInfo()
{
}


NetWorkInfo* NetWorkInfo::m_Instance=new NetWorkInfo();

NetWorkInfo* NetWorkInfo::getInstance()
{
	return m_Instance;
}

NetWorkInfo::~NetWorkInfo()
{
}

//���������Ϣ
void NetWorkInfo::showNetWorkInfo()
{
	//PIP_ADAPTER_INFO�ṹ��ָ��洢����������Ϣ
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
	//�õ��ṹ���С,����GetAdaptersInfo����
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);
	//����GetAdaptersInfo����,���pIpAdapterInfoָ�����;����stSize��������һ��������Ҳ��һ�������
	int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	if (ERROR_BUFFER_OVERFLOW == nRel)
	{
		//����������ص���ERROR_BUFFER_OVERFLOW
		//��˵��GetAdaptersInfo�������ݵ��ڴ�ռ䲻��,ͬʱ�䴫��stSize,��ʾ��Ҫ�Ŀռ��С
		//��Ҳ��˵��ΪʲôstSize����һ��������Ҳ��һ�������
		//�ͷ�ԭ�����ڴ�ռ�
		delete pIpAdapterInfo;
		//���������ڴ�ռ������洢����������Ϣ
		pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[stSize];
		//�ٴε���GetAdaptersInfo����,���pIpAdapterInfoָ�����
		nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	}
	if (ERROR_SUCCESS == nRel)
	{
		//���������Ϣ
		//�����ж�����,���ͨ��ѭ��ȥ�ж�
		while (pIpAdapterInfo)
		{
			cout << "�������ƣ�" << pIpAdapterInfo->AdapterName << endl;
			cout << "����������" << pIpAdapterInfo->Description << endl;
			cout << "����MAC��ַ��"/* << pIpAdapterInfo->Address*/;
			for (UINT i = 0; i < pIpAdapterInfo->AddressLength; i++)
			{
				if (i == pIpAdapterInfo->AddressLength - 1)
				{
					printf("%02x\n", pIpAdapterInfo->Address[i]);
				}
				else
				{
					printf("%02x-", pIpAdapterInfo->Address[i]);
				}
			}
			cout << "����IP��ַ��";
			//���������ж�IP,���ͨ��ѭ��ȥ�ж�
			IP_ADDR_STRING *pIpAddrString = &(pIpAdapterInfo->IpAddressList);
			do
			{
				cout << pIpAddrString->IpAddress.String << endl;
				pIpAddrString = pIpAddrString->Next;
			} while (pIpAddrString);
			pIpAdapterInfo = pIpAdapterInfo->Next;
			cout << "*****************************************************" << endl;
		}
		return;
	}
	//�ͷ��ڴ�ռ�
	CC_SAFE_DELETE(pIpAdapterInfo);
}

NetWorkInfo::GC::~GC()
{
	CC_SAFE_DELETE(m_Instance);
}
