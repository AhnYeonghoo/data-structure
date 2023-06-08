#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

//문서종류 구분
#define UNDEF_DOCUMENT        0
#define HWP_DOCUMENT          1
#define MSWORD_DOCUMENT       2
#define ANOTHER_DOCUMENT      3


//문서클래스의 최상위 클래스.
class Document
{
public:
	virtual bool Open(char* pFileName) = 0;
};

//한글문서 클래스
class HwpDocument : public Document
{
public:
	bool Open(char* pFileName)
	{
		ifstream ifs(pFileName);
		if (!ifs)
			return false;
		// -- HWP 고유 프로세싱
		return true;
	}
};

//워드문서 클래스
class MsWordDocument : public Document
{
public:
	bool Open(char* pFileName)
	{
		ifstream ifs(pFileName);
		if (!ifs)
			return false;
		// -- MS-Word 고유 프로세싱
		return true;
	}
};

//또 다른 문서 클래스
class AnotherDocument : public Document
{
public:
	bool Open(char* pFileName)
	{
		ifstream ifs(pFileName);
		if (!ifs)
			return false;
		// -- 알맞은 프로세싱
		return true;
	}
};

//응용프로그램 최상위 클래스.
class Application
{
private:
	map <string, Document *> docs_;
public:
	void NewDocument(char* pFileName)
	{
		Document *pDoc = CreateDocument(GetDocType(pFileName));
		if (pDoc == NULL) exit(0);
		docs_[pFileName] = pDoc;
		pDoc->Open(pFileName);
	}

	virtual Document* CreateDocument(int docType) //확장자를 받고 해당 객체를 반환.
	{
		switch (docType)
		{
		case HWP_DOCUMENT:
			return new HwpDocument;
		case MSWORD_DOCUMENT:
			return new MsWordDocument;
		}
		return 0;
	}

protected:
	int GetDocType(char *pFileName)              //확장자를 파악해줍니다.
	{
		char *pExt = strrchr(pFileName, '.');

		if (strcmp(pExt, ".hwp") == 0)
			return HWP_DOCUMENT;
		else if (strcmp(pExt, ".doc") == 0)
			return MSWORD_DOCUMENT;
		else
			return UNDEF_DOCUMENT;
	}
};

class HwpApplication : public Application { };

class MsWordApplication : public Application { };

class AnotherApplication : public Application
{
public:
	Document * CreateDocument(int docType)      //기타 응용프로그램은 함수를 따로 재정의
	{
		if (docType == ANOTHER_DOCUMENT)
			return new AnotherDocument;
		else // -- 자신이 생성할 수 없는 객체는 상위 클래스가 생성토록 위임
			return Application::CreateDocument(docType);
	}
};

int main()
{
	char filename[10] = "input.dat";

	AnotherApplication another;
	another.NewDocument(filename);

	return 0;
}