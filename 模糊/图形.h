#pragma once
#include <cflw数学.h>
#include <cflw图形_d2d.h>
#include <cflw图形_d3d11.h>
namespace 数学 = cflw::数学;
namespace 二维 = cflw::图形::d2d;
namespace 三维 = cflw::图形::d3d11;
class C图形 {
public:
	void f初始化(HWND);
	void f销毁();
	void f计算();
	void f更新();
	void f显示();
	三维::C三维 m三维;
	二维::C二维 m二维;
	二维::tp位图 m位图;
	二维::tp效果 m效果;
};