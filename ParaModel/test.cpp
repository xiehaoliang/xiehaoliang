#include"ParaModel.h"
#include <fstream>
#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
#include <QtCore/qstring.h>
using namespace std;





int Test(int& test1 ,int& test2)
{
	test1 = 0;
	test2 = 0;
	

    return 0 ;
}
int ReadTest(string sFile, std::vector<string>& vInfo)  //读一个文件txt
{
	ifstream inFile(sFile);                      //std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	vInfo.clear();
	// 打开文件失败
	if (inFile.fail()) 
	{
		cout << "open file false!" << endl;
		return 1;                              
	}                                         
	while (!inFile.eof())                      //判断是否到达文件尾部
	{
		string sLine;
		getline(inFile, sLine);               //wstring wb = conv.from_bytes(sLine);
		vInfo.push_back(sLine);
		                                      //wcout.imbue(locale("chs"));			
											  //更改区域设置 只为控制台输出显示
		                                     
	}

	inFile.close();
	//outFile.close();
	return 0;
}                                                 
int WriteTest(int& Wtest3)                 // writing on a text file  写文件操作
{
	ofstream out("out.txt");
	if (out.is_open())        //判断文件是否打开
	{                             
		out.close();          //关闭文件
	}
	return 0; 
}
int  main()
{
	vector<string>vInfo;

}
//int Test1 = 0;
//int ReadTest(string sFile, std::vector<string>& vInfo)  //读一个文件txt
//{
//	ifstream inFile(sFile);                      //std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
//	vInfo.clear();
//	                                            // 打开文件失败
//	if (inFile.fail()) {
//		cout << "open file false!" << endl;
//		return 1;
//	}
//	while (!inFile.eof())                      //判断是否到达文件尾部
//	{
//		string sLine;
//		getline(inFile, sLine);               //wstring wb = conv.from_bytes(sLine);
//		vInfo.push_back(sLine);
//		                                    //wcout.imbue(locale("chs"));			//更改区域设置 只为控制台输出显示
//		                                    //wcout << wb << endl;
//		                                    //std::string narrowStr = conv.to_bytes(wb);
//		                                    //outFile << narrowStr<<endl;
//	}
//
//	inFile.close();
//	//outFile.close();
//	return 0;
//}
//
//int ReadNodes(Ver3D& Ve3D )   // 写一个文本文件TXT
//{
//	ofstream file("out.k");
//	cout << "输入字符串:";
//	写文件开头
//	{
//		file << "*KEYWORD" << endl;
//		file << "*NODE" << endl;
//	}
//	int j = 1;
//	for (int i = 0; i < Ver3D.vMeshPt3D.size(); i++) 
//	{
//
//		打印node信息
//
//		file << std::setw(8) << j << std::setw(16) << std::setprecision(8) << Ve3D.vMeshPt3D[i].fXYZ[0]
//			<< std::setw(16) << std::scientific << std::setprecision(8) << Ve3D.vMeshPt3D[i].fXYZ[1]
//			<< std::setw(16) << std::scientific << std::setprecision(8) << Ve3D.vMeshPt3D[i].fXYZ[2]
//			<< std::setw(8) << std::setprecision(4) << 0
//			<< std::setw(8) << std::setprecision(4) << 0
//			<< std::endl;
//		j++;
//	}
//	file << "*ELEMENT_SOLID" << endl;   //打印solid信息
//	{
//		for (int i = 0; i < Ver3D.meshCube.size(); i++) {
//
//			file << std::setw(8) << Ve3D.meshCube[i].nIdx[0] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].nIdx[1] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].fIdx[0][0] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].fIdx[0][1] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].fIdx[0][2] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].fIdx[0][3] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].fIdx[1][0] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].fIdx[1][1] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].fIdx[1][2] << std::setw(8)
//				<< std::setw(8) << Ve3D.meshCube[i].fIdx[1][3] << std::setw(8)
//				<< std::endl;
//
//		}
//	}
//	file << setiosflags(ios::left) << "*END" << endl;
//	file.close();
//	return 0;
//}//// reading a text file  //读一个TXT文件
//int ReadTest() 
//{
//    char buffer[256];
//    ifstream in("test.txt");
//    if (!in.is_open())
//    {
//        cout << "Error opening file"; exit(1);
//    }
//    while (!in.eof())
//    {
//        in.getline(buffer, 100);
//        cout << buffer << endl;
//    }
//    return 0;
//}