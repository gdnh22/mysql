// demo_001.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string.h>
#include <iomanip>

#include ".\\include\\mysql_lib\\x86\\include\\mysql.h"
#include ".\\include\\v3.2.4\\mysql++.h"

#ifdef _DEBUG
#pragma comment(lib,".\\lib\\mysqlpp_vc2017D.lib")
#else
#pragma comment(lib,".\\lib\\mysqlpp_vc2017.lib")
#endif

int main(int argc, char* argv[])
{
	/*
/*
				VS2017下__cplusplus宏为199711L的问题
				发现需要在project属性页下面位置中做设置
				[Configuration Properties]->[C/C++]->[Command Line]->[Additional Options]
				加入下面参数
				/Zc:__cplusplus
				参考资料
				[1]《MSVC now correctly reports __cplusplus》
				https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/
				[2]《/Zc: __cplusplus （启用更新的 __cplusplus 宏）》
				https://docs.microsoft.com/zh-cn/cpp/build/reference/zc-cplusplus?view=vs-2017

				C++03：__cplusplus = 199711L
				C++11：__cplusplus = 201103L
				C++14：__cplusplus = 201402L   （VC2017默认值）
	-------------------- -
		作者：kagula086
		来源：CSDN
		原文：https ://blog.csdn.net/lee353086/article/details/89183652 
	版权声明：本文为博主原创文章，转载请附上博文链接！
	*/
    std::cout << "Hello mysql++ demo 001 !\n";
	mysqlpp::Connection conn(false);
	constexpr auto db_name = "hyibox";
	constexpr auto server_name = "212.64.109.40";
	constexpr auto user_name = "hiynn";
	constexpr auto password = "1111";
	constexpr auto sql_string_algorithm_config = "select * from ALGORITHM_CONFIG";
	if (conn.connect(db_name, server_name, user_name, password))
	{
		std::cout << "connection succuss." << std::endl;
		mysqlpp::Query query = conn.query(sql_string_algorithm_config);
		if (mysqlpp::StoreQueryResult res = query.store() ){
			std::cout << "We have:" << std::endl;
			//mysqlpp::StoreQueryResult::const_iterator it;
			for (auto it=res.begin(); it!=res.end(); ++it)
			{
				int iIndex = 0;
				mysqlpp::Row row = *it;
				std::cout << '\t' << row[iIndex++];
				std::cout << '\t' << row[iIndex++];
				std::cout << '\t' << row[iIndex++] << std::endl;
			}
		}
		else {
			std::cerr << "Failed to get ALGORITHM_CONFIG" << query.error() << std::endl;
		}
	}
	else
	{
		std::cerr << "mysql++ connection failed: " << conn.error() << std::endl;
	}
	char c = 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
