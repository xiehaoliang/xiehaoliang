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
int ReadTest(string sFile, std::vector<string>& vInfo)  //��һ���ļ�txt
{
	ifstream inFile(sFile);                      //std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	vInfo.clear();
	// ���ļ�ʧ��
	if (inFile.fail()) 
	{
		cout << "open file false!" << endl;
		return 1;                              
	}                                         
	while (!inFile.eof())                      //�ж��Ƿ񵽴��ļ�β��
	{
		string sLine;
		getline(inFile, sLine);               //wstring wb = conv.from_bytes(sLine);
		vInfo.push_back(sLine);
		                                      //wcout.imbue(locale("chs"));			
											  //������������ ֻΪ����̨�����ʾ
		                                     
	}

	inFile.close();
	//outFile.close();
	return 0;
}                                                 
int WriteTest(int& Wtest3)                 // writing on a text file  д�ļ�����
{
	ofstream out("out.txt");
	if (out.is_open())        //�ж��ļ��Ƿ��
	{                             
		out.close();          //�ر��ļ�
	}
	return 0; 
}
int  main()
{
	vector<string>vInfo;

}
//int Test1 = 0;
//int ReadTest(string sFile, std::vector<string>& vInfo)  //��һ���ļ�txt
//{
//	ifstream inFile(sFile);                      //std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
//	vInfo.clear();
//	                                            // ���ļ�ʧ��
//	if (inFile.fail()) {
//		cout << "open file false!" << endl;
//		return 1;
//	}
//	while (!inFile.eof())                      //�ж��Ƿ񵽴��ļ�β��
//	{
//		string sLine;
//		getline(inFile, sLine);               //wstring wb = conv.from_bytes(sLine);
//		vInfo.push_back(sLine);
//		                                    //wcout.imbue(locale("chs"));			//������������ ֻΪ����̨�����ʾ
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
//int ReadNodes(Ver3D& Ve3D )   // дһ���ı��ļ�TXT
//{
//	ofstream file("out.k");
//	cout << "�����ַ���:";
//	д�ļ���ͷ
//	{
//		file << "*KEYWORD" << endl;
//		file << "*NODE" << endl;
//	}
//	int j = 1;
//	for (int i = 0; i < Ver3D.vMeshPt3D.size(); i++) 
//	{
//
//		��ӡnode��Ϣ
//
//		file << std::setw(8) << j << std::setw(16) << std::setprecision(8) << Ve3D.vMeshPt3D[i].fXYZ[0]
//			<< std::setw(16) << std::scientific << std::setprecision(8) << Ve3D.vMeshPt3D[i].fXYZ[1]
//			<< std::setw(16) << std::scientific << std::setprecision(8) << Ve3D.vMeshPt3D[i].fXYZ[2]
//			<< std::setw(8) << std::setprecision(4) << 0
//			<< std::setw(8) << std::setprecision(4) << 0
//			<< std::endl;
//		j++;
//	}
//	file << "*ELEMENT_SOLID" << endl;   //��ӡsolid��Ϣ
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
//}//// reading a text file  //��һ��TXT�ļ�
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