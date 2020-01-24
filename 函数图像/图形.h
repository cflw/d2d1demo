#pragma once
#include <cflw数学.h>
#include <cflw图形_d2d.h>
namespace 数学 = cflw::数学;
namespace 二维 = cflw::图形::d2d;
class C图形 {
public:
	void f初始化(HWND);
	void f销毁();
	void f计算();
	void f更新();
	void f显示();
	二维::C二维 m二维;
	二维::tp画图形 m画图形;
	std::vector<std::function<float(float)>> ma函数;
};