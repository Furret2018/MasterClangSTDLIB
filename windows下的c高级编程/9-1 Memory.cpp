#define _WIN32_WINNT 0x0500
#define WINVER 0x0500
#include 
#include 
#include 
#include 
#pragma comment(lib, “Shlwapi.lib”)

//格式化和显示内存状态的辅助方法
void DisplayMemory(DWORDLONG ullAvail, DWORDLONG ullTotal)
{
	TCHAR szAvail[MAX_PATH];
	::StrFormatByteSize(ullAvail, szAvail, MAX_PATH);
	TCHAR szTotal[MAX_PATH];
	::StrFormatByteSize(ullTotal, szTotal, MAX_PATH);
	std::cout <<"Available:" << szAvail  << ",Total:" <<szTotal;
}

void main()
{
	//分配和检取内存状态
	MEMORYSTATUSEX msx;
	::ZeroMenory(&msx,sizeof(msx));
	msx.dwLength=sizeof(msx);
	if(::GlobalMemoryStatusEx(&msx))
	{
		//显示当前加载
		std::cout << "Memory utilization:" << msx.DWMEMORYLOAD << "%" <<std::endl;
		//显示虚拟内存 
		std::cout << "Virtual memory";
		::DisplayMemory(msx.ullAvailVirtual, msx.ullTotalVirtual); std::cout<<std::endl;
		
		//显示物理内存
		std::cout<<"Physical memory";
		::DisplayMemory(msx.ullAvailPhys, msx.ullTotalPhys); std::cout<<std::endl;
		
		//显示页面文件的内存
		std::cout << "Page file memory";
		::DisplayMemory(msx.ullAvailPageFile, msx.ullTotalPageFile); std::cout<<std::endl;
		
		//显示VLM状态
		TCHAR szVLM[MAX_PATH];
		::StrFormatByteSize(msx.ullAvailExtendedVirtual, szVLM, MAX_PATH);
		std::cout << "VLM:" << szVLM << std::endl; 
	}
	
	return 0;
}
